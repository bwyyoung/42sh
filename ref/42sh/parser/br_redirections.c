/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   br_redirections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:11:31 by mda-cost          #+#    #+#             */
/*   Updated: 2016/11/07 19:11:32 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

static void	redir_end(t_node *node)
{
	if (node->type == REDIR_L
			|| node->type == F_REDIR_L || node->type == HEREDOC)
		redir_end_read(node);
	else
		redir_end_write(node);
}

static void	redir_before_end(t_node *node)
{
	if (node->type == REDIR_L
			|| node->type == F_REDIR_L || node->type == HEREDOC)
		redir_before_read(node);
	else
		redir_before_write(node);
}

void		br_redirections(t_node *node, t_info *info)
{
	t_node	*tmp;

	tmp = node;
	ft_update_fd(node->left);
	while (tmp->right)
	{
		if (tmp->right->type >= REDIR_R && tmp->right->type <= F_REDIR_L)
			redir_before_end(tmp);
		else
			redir_end(tmp);
		tmp = tmp->right;
	}
	ft_execdetect(node->left, info);
}
