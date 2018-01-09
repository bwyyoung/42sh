/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/17 11:08:11 by mda-cost          #+#    #+#             */
/*   Updated: 2016/06/01 15:58:50 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

static int	ft_dot_slash(char *cmd)
{
	if (cmd[0] == '/' || (cmd[0] == '.' && cmd[1] == '/'))
		return (1);
	return (0);
}

static int	ft_set_paths(t_env *e, char **env)
{
	int		i;

	i = 0;
	while ((env != NULL) && env[i])
	{
		if (ft_strnequ("PATH=", env[i], 5))
		{
			e->paths = ft_strsplit(env[i] + 5, ':');
			return (1);
		}
		i++;
	}
	return (0);
}

static int	ft_binary(char **cmd, t_env *e)
{
	if (ft_set_paths(e, e->env) == 1)
	{
		e->final_path = ft_path_builder(cmd, e);
		if (e->final_path != NULL)
			return (0);
	}
	return (-1);
}

static int	ft_detect(char **cmd, t_env *e)
{
	int		acc;

	acc = -1;
	if (ft_dot_slash(cmd[0]) == 1)
	{
		if ((acc = access(cmd[0], X_OK)) == 0)
			e->final_path = ft_strdup(cmd[0]);
		return (acc);
	}
	acc = ft_what_builtin(cmd);
	if (acc >= BUILTIN_ECHO)
	{
		if (acc >= BUILTIN_ECHO && acc <= BUILTIN_SETENV)
			return (acc);
		if (acc > BUILTIN_SETENV)
		{
			ft_putstr_fd("42sh: builtin ", 2);
			ft_putstr_fd(cmd[0], 2);
			ft_putendl_fd(" wrong usage", 2);
			return (-2);
		}
	}
	acc = ft_binary(cmd, e);
	return (acc);
}

void		ft_interpret(char **cmd, t_env *e)
{
	int		acc;

	acc = -1;
	if (cmd == NULL || cmd[0] == NULL)
		exit(-1);
	e->cmd = ft_tabdup(cmd);
	acc = ft_detect(e->cmd, e);
	if (acc == 0)
		ft_now(e->final_path, e->cmd, e->env);
	if (acc == BUILTIN_ENV)
		builtin_env(e);
	if (acc == BUILTIN_SETENV)
		builtin_setenv(e);
	if (acc == BUILTIN_ECHO)
		builtin_echo(e);
	if (acc == -1)
	{
		ft_putstr_fd("42sh: command not found: ", 2);
		ft_putendl_fd(e->cmd[0], 2);
	}
	exit(acc);
}
