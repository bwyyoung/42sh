/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 16:13:58 by byoung-w          #+#    #+#             */
/*   Updated: 2014/12/25 07:41:20 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			update_fil_params(t_btree **root_fil, t_btree **node,
size_t padding[NUM_COLUMNS])
{
	btree_updatepadding(*node, padding);
	btree_insert_node(root_fil, node);
}

static void		analysedir_l_parse(size_t padding[NUM_COLUMNS],
char *thedir, int numfiles, DIR *pdir)
{
	struct dirent	*pdirent;
	t_btree			*node;
	t_btree			*root;
	quad_t			bytes;
	char			str_2[PATH_MAX];

	bytes = 0;
	root = NULL;
	while (((pdirent = readdir(pdir)) != NULL))
	{
		ft_strjoin_opti(thedir, pdirent->d_name, str_2);
		node = l_getfileinfo(str_2, 0);
		btree_updatepadding(node, padding);
		bytes += btree_insert_node(&root, &node);
		if ((g_ls_flags.g_lsa) ||
		(!g_ls_flags.g_lsa && !util_is_hidden(node->c6_fnm)))
			numfiles++;
	}
	print_totalbytes(numfiles, bytes);
	btree_print(root, padding);
	btree_print_recursive(root);
	btree_delete_tree(root);
}

static int		analysedir_g_lsd(char *thedir, size_t padding[NUM_COLUMNS])
{
	int			lsa;
	t_btree		*node;

	lsa = g_ls_flags.g_lsa;
	if (!(node = l_getfileinfo(thedir, 1)))
		return (0);
	btree_updatepadding(node, padding);
	g_ls_flags.g_lsa = 1;
	btree_print(node, padding);
	g_ls_flags.g_lsa = lsa;
	btree_delete_tree(node);
	return (1);
}

int				analysedir(char *thedir)
{
	DIR				*pdir;
	size_t			padding[NUM_COLUMNS];
	size_t			*p;
	int				numfiles;
	char			str_1[ft_strlen(thedir) + 1];

	util_checkdirslash(thedir, str_1);
	g_ls_flags.g_numdirs++;
	pdir = opendir(str_1);
	numfiles = 0;
	if (pdir == NULL)
		return (error_print());
	p = padding;
	l_init_padding(&p);
	if (g_ls_flags.g_lsd)
		analysedir_g_lsd(thedir, padding);
	else
		analysedir_l_parse(padding, str_1, numfiles, pdir);
	return (closedir(pdir) == 0);
}

char			*file_name(char *file_path)
{
	unsigned int		i;
	char				*str;

	i = 0;
	if (file_path == NULL)
		return (NULL);
	while (file_path[i])
		i++;
	while (file_path[i] != '/' && i != 0)
		i--;
	if ((file_path[i] == '/') || (file_path[i] == '.'))
		i++;
	str = ft_strsub(file_path, i, ft_strlen(file_path) - i);
	return (str);
}
