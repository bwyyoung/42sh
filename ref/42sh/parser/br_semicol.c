/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   br_semicol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 18:14:18 by mda-cost          #+#    #+#             */
/*   Updated: 2016/11/03 21:00:45 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

static void	br_semico_fork(t_node *node, t_info *info)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		ft_execdetect(node->left, info);
	else
	{
		waitpid(-1, 0, 0);
		ft_execdetect(node->right, info);
	}
}

void		br_semicol(t_node *node, t_info *info)
{
	if (node->left && node->right)
		br_semico_fork(node, info);
}
