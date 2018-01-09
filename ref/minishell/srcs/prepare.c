/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/17 19:58:07 by mda-cost          #+#    #+#             */
/*   Updated: 2015/04/20 16:46:30 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int			ft_check_dot_slash(char *cmd)
{
	if (cmd[0] == '/' || (cmd[0] == '.' && cmd[1] == '/'))
		return (1);
	return (0);
}

int			ft_is_builtin(char **cmd)
{
	if (ft_strcmp(cmd[0], "cd") == 0 || ft_strcmp(cmd[0], "exit") == 0
		|| ft_strcmp(cmd[0], "setenv") == 0 ||
		ft_strcmp(cmd[0], "unsetenv") == 0 || ft_strcmp(cmd[0], "env") == 0)
	{
		return (1);
	}
	else
		return (0);
}

int			ft_set_paths(t_env *e)
{
	int				i;

	i = 0;
	while ((e->env != NULL) && e->env[i])
	{
		if (ft_strnequ("PATH=", e->env[i], 5))
		{
			e->paths = ft_strsplit(e->env[i] + 5, ':');
			return (1);
		}
		i++;
	}
	return (0);
}

void		ft_is_builtin_or_not(char **cmd, t_env *e)
{
	if (ft_is_builtin(cmd) == 1)
		ft_builtin(cmd, e);
	else
		ft_prepare(cmd, e);
}

void		ft_prepare(char **cmd, t_env *e)
{
	int		acc;

	acc = -1;
	if (ft_check_dot_slash(cmd[0]) == 1)
	{
		if ((acc = access(cmd[0], X_OK)) == 0)
			ft_fork_exec(cmd[0], cmd, e);
		else
		{
			ft_putstr_fd("ft_minishell2: command not found: ", 2);
			ft_putendl_fd(cmd[0], 2);
		}
	}
	else
	{
		if (ft_set_paths(e) == 1)
			ft_check_cmd(cmd, e);
		else
			ft_putendl("path is not set");
	}
}
