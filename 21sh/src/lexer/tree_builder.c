/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_builder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/12/25 07:29:01 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh.h"

t_tkn	*highest_priority_node(t_tkn *tree)
{
	t_tkn	*tmp;
	t_tkn	*top;

	tmp = tree;
	top = tmp;
	while (tmp)
	{
		if (tmp->type > top->type)
			top = tmp;
		tmp = tmp->right;
	}
	return (top);
}

t_tkn	*get_left_branch(t_tkn *tree, t_tkn *head)
{
	t_tkn	*tmp;

	if (!tree)
		return (NULL);
	tmp = tree;
	while (!(tmp == head || tmp->right == head))
		tmp = tmp->right;
	if (tmp == head)
		return (NULL);
	tmp->right = NULL;
	return (tree);
}

t_tkn	*build_tree(t_tkn *tree)
{
	t_tkn	*head;
	t_tkn	*left;
	t_tkn	*right;
	t_tkn	*tmp;

	tmp = tree;
	if (!tree)
		return (NULL);
	head = highest_priority_node(tree);
	right = head->right;
	left = get_left_branch(tree, head);
	head->left = build_tree(left);
	head->right = build_tree(right);
	return (head);
}
