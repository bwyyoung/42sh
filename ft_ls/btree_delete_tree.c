/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_delete_tree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/11 18:13:51 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/11 18:14:24 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		btree_delete_tree(t_btree *node)
{
	if ((node) == NULL)
		return ;
	btree_delete_tree((node)->left);
	btree_delete_tree((node)->right);
	btree_free_node(&node);
	node = NULL;
}

void		safe_memory_free_v(void **pointer_address)
{
	if (pointer_address != NULL && *pointer_address != NULL)
	{
		free(*pointer_address);
		*pointer_address = NULL;
	}
}

void		safe_memory_free_c(char **pointer_address)
{
	if (pointer_address == NULL || *pointer_address == NULL)
		return;
	free(*pointer_address);
	*pointer_address = NULL;
}

void			btree_free_node(t_btree **node)
{
	if ((*node) == NULL)
		return ;
	safe_free_c((*node)->c0_prm);
	safe_free_c((*node)->c2_uid);
	safe_free_c((*node)->c3_grp);
	safe_free_c((*node)->c5_ftm);
	safe_free_c((*node)->c6_fnm);
	safe_free_c((*node)->filepath);
	safe_free_c((*node)->major);
	safe_free_v((*node));
}
