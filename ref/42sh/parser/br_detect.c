/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   br_detect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 19:10:13 by mda-cost          #+#    #+#             */
/*   Updated: 2016/11/03 21:00:54 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

static void	exec_builtin(char **cmd, int builtin, t_info *info)
{
	if (cmd != NULL || cmd[0] != NULL)
	{
		info->e->cmd = ft_tabdup(cmd);
		if (builtin == BUILTIN_CD)
			builtin_cd(info->e);
		if (builtin == BUILTIN_SETENV)
			builtin_setenv(info->e);
		if (builtin == BUILTIN_UNSETENV)
			builtin_unsetenv(info->e);
		if (builtin == BUILTIN_EXIT)
			builtin_exit(info);
		ft_freepaths(info->e);
	}
}

void		ft_execdetect(t_node *node, t_info *info)
{
	if (node->type != 0)
		(*info->tab_browser[node->type])(node, info); // array of functions
	else
	{
		ft_update_fd(node);
		ft_interpret(node->cmd, info->e);
	}
}

void		ft_browse_start(t_node *root, t_info *info)
{
	pid_t	pid;
	int		builtin;

	builtin = 0;
	if (root->type == 0 &&
		((builtin = ft_what_builtin(root->cmd)) >= BUILTIN_SETENV))
		exec_builtin(root->cmd, builtin, info);
	else if (info->sh->exit == 1)
		return ;
	else
	{
		pid = fork();
		if (pid == 0)
			ft_execdetect(root, info);
		else
			waitpid(-1, 0, 0);
	}
}
