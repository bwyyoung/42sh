/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 17:24:26 by mda-cost          #+#    #+#             */
/*   Updated: 2016/06/01 15:58:24 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

static char	**env_only_cmd(t_env *e, int i)
{
	int		size;
	int		j;
	char	**n_cmd;

	j = 0;
	size = ft_tablen(e->cmd);
	if (!(n_cmd = (char **)malloc(sizeof(char *) * (size - i + 1))))
		ft_error("env_only_cmd: malloc failed");
	while (e->cmd[i + j])
	{
		n_cmd[j] = ft_strdup(e->cmd[i + j]);
		j++;
	}
	n_cmd[j] = NULL;
	ft_arrayfree(e->cmd);
	e->cmd = NULL;
	return (n_cmd);
}

static int	env_var_tmp(t_env *e, int i)
{
	char	*pos;

	while (e->cmd[i] && (pos = ft_strchr(e->cmd[i], '=')))
	{
		e->env = env_add_tmp(e->env, e->cmd[i]);
		i++;
	}
	return (i);
}

static void	env_args(t_env *e)
{
	int		i;

	i = 0;
	if (ft_strcmp(e->cmd[1], "-i") == 0)
	{
		ft_arrayfree(e->env);
		e->env = NULL;
		i = env_var_tmp(e, 2);
	}
	else
		i = env_var_tmp(e, 1);
	if (e->cmd[i])
	{
		e->cmd = env_only_cmd(e, i);
		ft_interpret(e->cmd, e);
	}
	else
		ft_putarray(e->env);
}

void		builtin_env(t_env *e)
{
	char	**save;

	save = NULL;
	if (e->env != NULL)
		save = ft_tabdup(e->env);
	if (ft_tablen(e->cmd) == 1)
		ft_putarray(e->env);
	else
		env_args(e);
	ft_arrayfree(e->env);
	e->env = save;
}
