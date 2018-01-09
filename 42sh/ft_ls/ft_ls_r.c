/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 09:50:50 by byoung-w          #+#    #+#             */
/*   Updated: 2014/12/25 07:49:13 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				print_directoryname(t_btree *node, int override, int first)
{
	if ((g_ls_flags.g_lsa) || (!g_ls_flags.g_lsa &&
!util_is_hidden((node->c6_fnm))) || override)
		if (g_ls_flags.g_numdirs > 1)
		{
			if (!first)
				ft_putchar('\n');
			ft_putstr(node->filepath);
			ft_putstr(":\n");
		}
}

void				print_totalbytes(int numfiles, int bytes)
{
	if (numfiles > 0 && g_ls_flags.g_lsl)
	{
		ft_putstr("total ");
		ft_putnbr(bytes);
		ft_putchar('\n');
	}
}

void				btree_recursive_action(t_btree *node)
{
	if ((ft_strcmp(node->c6_fnm, ".") && ft_strcmp(node->c6_fnm, "..")) &&
		!(S_ISLNK(node->st_mode)) && (S_ISDIR(node->st_mode)))
	{
		if (node->c6_fnm && ((g_ls_flags.g_lsa) ||
								 (!g_ls_flags.g_lsa && ((node->c6_fnm[0]) != '.'))))
		{
			g_ls_flags.g_numdirs++;
			print_directoryname(node, 0, 0);
			analysedir(node->filepath);
		}
	}
};

void				btree_print_recursive(t_btree *node)
{
	if (!g_ls_flags.g_lsbigr)
		return ;
	if ((node) == NULL)
		return ;
	if (g_ls_flags.g_lsr)
		btree_print_recursive((node)->right);
	else
		btree_print_recursive((node)->left);
	btree_recursive_action(node);
	if (g_ls_flags.g_lsr)
		btree_print_recursive((node)->left);
	else
		btree_print_recursive((node)->right);
}
