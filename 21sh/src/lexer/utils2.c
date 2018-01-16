/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/12/25 07:29:01 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh.h"

t_tkn	*tkn_search_node(t_tkn *node, char *data)
{
	t_tkn *match;

	if (!node)
		return (NULL);
	else if (ft_strcmp(node->data, data) == 0)
		return (node);
	else if ((match = tkn_search_node(node->left, data)))
		return (match);
	else if ((match = tkn_search_node(node->right, data)))
		return (match);
	return (NULL);
}

t_tkn	*tkn_last(t_tkn *node)
{
	while (node->right)
		node = node->right;
	return (node);
}

void	skip_and_sort(t_tkn **tkns, t_tkn **lst_sep)
{
	*tkns = (*tkns)->right;
	(!(*tkns) || in_range((*tkns)->type, 4, 6)) ? tkns_sort(lst_sep) : (0);
}

int		prev_node_not_fd_aggr(t_tkn *start, t_tkn *end)
{
	while (start->right != end)
		start = start->right;
	return (start->type != 3);
}

void	tkn_del(t_tkn *start, t_tkn **tkn)
{
	while (start->right != *tkn)
		start = start->right;
	start->right = start->right->right;
	ft_strdel(&(*tkn)->data);
	free(*tkn);
}
