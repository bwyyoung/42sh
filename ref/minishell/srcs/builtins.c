/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 15:07:22 by mda-cost          #+#    #+#             */
/*   Updated: 2015/04/20 16:45:12 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	ft_start_env(char **cmd, t_env *e)
{
	if (ft_tablen(cmd) == 1)
		ft_print_test(e->env);
	else
	{
		ft_builtin_env(cmd, e);
	}
}

void	ft_builtin(char **cmd, t_env *e)
{
	if (ft_strcmp(cmd[0], "env") == 0)
		ft_start_env(cmd, e);
	else if (ft_strcmp(cmd[0], "exit") == 0)
	{
		if (cmd[1])
			exit(ft_atoi(cmd[1]));
		else
			exit(0);
	}
	else if (ft_strcmp(cmd[0], "setenv") == 0)
	{
		ft_pre_setenv(cmd, e);
	}
	else if (ft_strcmp(cmd[0], "unsetenv") == 0)
	{
		ft_pre_unsetenv(cmd, e);
	}
	else if (ft_strcmp(cmd[0], "cd") == 0)
		ft_cd(cmd, e);
}
