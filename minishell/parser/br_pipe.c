/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   br_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 18:16:43 by mda-cost          #+#    #+#             */
/*   Updated: 2016/11/03 21:00:22 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

void		br_pipe(t_node *node, t_info *info)
{
	int		p[2];
	pid_t	pid;
	int		status;

	if (pipe(p) == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			dup2(p[1], node->stdout);
			close(p[0]);
			ft_execdetect(node->left, info);
		}
		else
		{
			dup2(p[0], node->stdin);
			close(p[1]);
			ft_execdetect(node->right, info);
			waitpid(-1, &status, 0);
		}
	}
	else
	{
		exit(2);
	}
}
