/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 09:50:50 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/03 11:22:41 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		print_params(t_btree *root_dir, t_btree *root_fil,
size_t padding[NUM_COLUMNS])
{
	int		lsa;

	lsa = g_ls_flags.g_lsa;
	if (g_ls_flags.g_lsd)
		g_ls_flags.g_lsa = 1;
	btree_print(root_fil, padding);
	if (g_ls_flags.g_lsd)
		g_ls_flags.g_lsa = 0;
	g_ls_flags.g_lsa = lsa;
	if (root_fil != NULL && root_dir != NULL)
		ft_putchar('\n');
	btree_analysedir(root_dir);
}

static int		break_params_node(t_btree **node, t_btree **root_dir
, t_btree **root_err)
{
	if ((*node)->m_errno > 0)
	{
		btree_insert_node(root_err, node);
		g_ls_flags.g_numdirs++;
		return (1);
	}
	else if ((S_ISDIR((*node)->st_mode) ||
(util_issymlinktargetdir((*node)))) && !g_ls_flags.g_lsd)
	{
		g_ls_flags.g_numdirs++;
		btree_insert_node(root_dir, node);
		return (1);
	}
	return (0);
}

static void		break_params(int (*m_cmp)(t_btree **, t_btree **),
size_t padding[NUM_COLUMNS], int numargs, char **argv)
{
	g_ls_flags.root_dir = NULL;
	g_ls_flags.root_fil = NULL;
	g_ls_flags.root_err = NULL;
	while (numargs > 0)
	{
		g_ls_flags.mode_direct_target = true;
		if (!(g_ls_flags.node = l_getfileinfo(*argv, 1)))
			return ;
		((!g_ls_flags.g_lsp) ? (g_ls_flags.mode_direct_target = false) : (0));
		if (!break_params_node(&g_ls_flags.node, &g_ls_flags.root_dir,
							&g_ls_flags.root_err))
			update_fil_params(&g_ls_flags.root_fil, &g_ls_flags.node, padding);
		argv++;
		numargs--;
	}
	btree_analyseerr(g_ls_flags.root_err);
	g_ls_flags.g_cmp = m_cmp;
	print_params(g_ls_flags.root_dir, g_ls_flags.root_fil, padding);
	btree_delete_tree(g_ls_flags.root_dir);
	btree_delete_tree(g_ls_flags.root_fil);
	btree_delete_tree(g_ls_flags.root_err);
}

void			analyse_params(int numargs, char **argv)
{
	int			(*m_cmp)(t_btree **, t_btree **);
	size_t		padding[NUM_COLUMNS];
	size_t		*p;

	m_cmp = g_ls_flags.g_cmp;
	p = padding;
	l_init_padding(&p);
	break_params(m_cmp, padding, numargs, argv);
}
