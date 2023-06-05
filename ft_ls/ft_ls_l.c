/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 09:50:50 by byoung-w          #+#    #+#             */
/*   Updated: 2014/12/25 06:56:39 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Failure by acl_get_link_np after free is called, when checking /dev
*/

static int		getacl(char *name)
{
	acl_t		facl;
	acl_entry_t	ae;

	if (ft_strstr(name, "/dev") != NULL)
		return (0);
	facl = acl_get_file(name, ACL_TYPE_DEFAULT);//acl_get_link_np(name, ACL_TYPE_EXTENDED);
	if (facl && (acl_get_entry(facl, ACL_FIRST_ENTRY, &ae) == -1))
	{
		acl_free(facl);
		return (0);
	}
	if (facl != NULL)
	{
		acl_free(facl);
		return (1);
	}
	acl_free(facl);
	return (0);
}

/*
**TODO: CHECK MAJOR For efficiency after change
*/

static char		filetype(t_stat *fstat, mode_t *st_mode, t_btree **node)
{
	if (S_ISCHR(*st_mode) || S_ISBLK(*st_mode))
	{
		if (!major(fstat->st_rdev))
			(*node)->major = ft_strdup("0,");
		else
		{
			(*node)->major = ft_itoa(major(fstat->st_rdev) * 10);
			(*node)->major[ft_strlen((*node)->major) - 1] = ',';
		}
		(*node)->c4_byt = minor(fstat->st_rdev);
		if (S_ISBLK(*st_mode))
			return ('b');
		return ('c');
	}
	if (S_ISDIR(*st_mode))
		return ('d');
	if (S_ISLNK(*st_mode))
		return ('l');
	if (S_ISSOCK(*st_mode))
		return ('s');
	if (S_ISFIFO(*st_mode))
		return ('p');
	return ('-');
}

static void		getfp_rwx_2(t_stat *fstat, t_btree **n)
{
	if (!((*n)->c0_prm = ft_memalloc(12)))
		exit(0);
	g_ls_flags.sticky = 't';
	ft_strcpy((*n)->c0_prm, "------------");
	(*n)->st_mode = fstat->st_mode;
	(*n)->c0_prm[0] = filetype(fstat, &(fstat->st_mode), n);
	(fstat->st_mode & S_IRUSR) ? ((*n)->c0_prm[1] = 'r') : (0);
	(fstat->st_mode & S_IWUSR) ? ((*n)->c0_prm[2] = 'w') : (0);
	(fstat->st_mode & S_IXUSR) ? ((*n)->c0_prm[3] = 'x') : (0);
	(fstat->st_mode & S_IRGRP) ? ((*n)->c0_prm[4] = 'r') : (0);
	(fstat->st_mode & S_IWGRP) ? ((*n)->c0_prm[5] = 'w') : (0);
	(fstat->st_mode & S_IXGRP) ? ((*n)->c0_prm[6] = 'x') : (0);
	(fstat->st_mode & S_IROTH) ? ((*n)->c0_prm[7] = 'r') : (0);
	(fstat->st_mode & S_IWOTH) ? ((*n)->c0_prm[8] = 'w') : (0);
	(fstat->st_mode & S_IXOTH) ? ((*n)->c0_prm[9] = 'x') : (0);
	(*n)->c0_prm[11] = '\0';
	(*n)->c1_nlink = fstat->st_nlink;
	if ((g_ls_flags.pwd = getpwuid(fstat->st_uid)) != NULL)
		(*n)->c2_uid = ft_strdup(g_ls_flags.pwd->pw_name);
	else
		(*n)->c2_uid = ft_itoa(fstat->st_uid);
	(*n)->c0_prm[10] = ' ';
	sticky_bit(fstat, n);
}

static char		*getfp(t_stat *fstat, char *file_path, t_btree **node)
{
	getfp_rwx_2(fstat, node);
	(*node)->c0_prm[10] = ' ';
    g_ls_flags.list_len = listxattr(file_path, g_ls_flags.list, XATTR_SIZE);
	//g_ls_flags.list_len = listxattr(file_path, g_ls_flags.list, XATTR_SIZE,
	//((*node)->c0_prm[0] == 'l' ? XATTR_NOFOLLOW : 0));
	if (g_ls_flags.list_len > 0)
		(*node)->c0_prm[10] = '@';
	else if (getacl(file_path))
		(*node)->c0_prm[10] = '+';
	return ((*node)->c0_prm);
}

t_btree			*l_getfileinfo(char *file, int fulldir)
{
	ft_memset(&g_ls_flags.filestat, 0, sizeof(t_stat));
	if (!(g_ls_flags.node2 = btree_create_node()))
		return (NULL);
	if (!fulldir)
		g_ls_flags.node2->c6_fnm = file_name(file);
	else
		g_ls_flags.node2->c6_fnm = ft_strdup(file);
	if (lstat(file, &g_ls_flags.filestat) != 0 && (g_ls_flags.node2->m_errno = errno))
		return (g_ls_flags.node2);
	g_ls_flags.node2->c4_byt = g_ls_flags.filestat.st_size;
	g_ls_flags.grp = getgrgid(g_ls_flags.filestat.st_gid);
	if (g_ls_flags.grp != NULL)
		g_ls_flags.node2->c3_grp = ft_strdup(g_ls_flags.grp->gr_name);
	else
		g_ls_flags.node2->c3_grp = ft_itoa(g_ls_flags.filestat.st_gid);
	if (file && ft_strlen(file) > 0 && ft_isprint(file[0]))
		g_ls_flags.node2->filepath = ft_strdup(file);
	g_ls_flags.node2->c5_ftm = file_time(&g_ls_flags.filestat, &g_ls_flags.node2);
	g_ls_flags.node2->id = rand();
	g_ls_flags.node2->st_blocks = g_ls_flags.filestat.st_blocks;
	getfp(&g_ls_flags.filestat, file, &g_ls_flags.node2);
	return (g_ls_flags.node2);
}
