/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_opti.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 09:50:50 by byoung-w          #+#    #+#             */
/*   Updated: 2014/12/25 07:49:13 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*file_name_opti(char *file_path)
{
	unsigned int		i;

	i = 0;
	if (file_path == NULL)
		return (NULL);
	while (file_path[i])
		i++;
	while (file_path[i] != '/' && i != 0)
		i--;
	if ((file_path[i] == '/') || (file_path[i] == '.'))
		i++;
	return (file_path + i);
}

char			*ft_strjoin_opti(char *first, char *second, char *dest)
{
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(first);
	len2 = ft_strlen(second);
	ft_memcpy(dest, first, len1);
	ft_memcpy(dest + len1, second, len2 + 1);
	return (dest);
};

void			reset_display(void)
{
	g_ls_flags.g_ls_display_bigu = 0;
	g_ls_flags.g_ls_display_c = 0;
	g_ls_flags.g_ls_display_u = 0;
}

void			reset_sort(void)
{
	if (g_ls_flags.g_lsbigs)
		return;
	g_ls_flags.g_lsu = 0;
	g_ls_flags.g_lsbigu = 0;
	g_ls_flags.g_lsc = 0;
	g_ls_flags.g_lsbigs = 0;
	g_ls_flags.g_lsbigt = 0;
}

void			sticky_bit(t_stat *fstat, t_btree **n)
{
	if ((*n)->c0_prm[9] == '-')
		g_ls_flags.sticky = 'T';
	(*n)->c0_prm[9] = (fstat->st_mode & S_ISVTX) ?
					  g_ls_flags.sticky : (*n)->c0_prm[9];
	((fstat->st_mode & S_ISUID) && ((*n)->c0_prm[3] == 'x')) ?
	((*n)->c0_prm[3] = 's') : (0);
	((fstat->st_mode & S_ISUID) && ((*n)->c0_prm[3] == '-')) ?
	((*n)->c0_prm[3] = 'S') : (0);
	((fstat->st_mode & S_ISGID) && ((*n)->c0_prm[6] == 'x')) ?
	((*n)->c0_prm[6] = 's') : (0);
	((fstat->st_mode & S_ISGID) && ((*n)->c0_prm[6] == '-')) ?
	((*n)->c0_prm[6] = 'S') : (0);
}