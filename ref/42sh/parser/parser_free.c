/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 14:07:00 by mda-cost          #+#    #+#             */
/*   Updated: 2016/11/03 21:02:41 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

void		ft_free_tree(t_node *tree)
{
	if (!tree)
		return ;
	if (tree->left)
		ft_free_tree(tree->left);
	if (tree->right)
		ft_free_tree(tree->right);
	if (tree->elem)
		free(tree->elem);
	if (tree->cmd)
		ft_arrayfree(tree->cmd);
	free(tree);
}

void		ft_freepaths(t_env *e)
{
	ft_arrayfree(e->cmd);
	ft_arrayfree(e->paths);
	ft_freestr(e->final_path);
	e->cmd = NULL;
	e->paths = NULL;
	e->final_path = NULL;
}
