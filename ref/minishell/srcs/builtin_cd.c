/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/19 17:53:34 by mda-cost          #+#    #+#             */
/*   Updated: 2015/04/24 17:54:54 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int			ft_syntax_cd(char **cmd)
{
	int		nb;

	nb = ft_tablen(cmd);
	if (nb > 2)
	{
		ft_putendl_fd("ft_minishell1: cd: Too many arguments", 2);
		return (-1);
	}
	else
		return (nb);
}

int			ft_change_rep(char *direction, t_env *e)
{
	char	*old_path;
	char	*new_path;

	old_path = NULL;
	old_path = getcwd(NULL, 1024);
	new_path = NULL;
	if (chdir(direction) > -1)
	{
		new_path = getcwd(NULL, 1024);
		ft_setenv("OLDPWD", old_path, e);
		ft_setenv("PWD", new_path, e);
		ft_freestr(new_path);
	}
	else
	{
		ft_putstr_fd("cd: no such file or directory: ", 2);
		ft_putendl_fd(direction, 2);
	}
	ft_freestr(old_path);
	return (1);
}

int			ft_back_rep(t_env *e)
{
	char	*new_path;

	new_path = ft_return_rep("OLDPWD=", e->env, 7);
	if (new_path != NULL)
	{
		ft_change_rep(new_path, e);
		return (1);
	}
	else
	{
		ft_putendl_fd("cd: missing key OLDPWD", 2);
		return (0);
	}
}

int			ft_back_home(t_env *e)
{
	char	*new_path;

	new_path = ft_return_rep("HOME=", e->env, 5);
	if (new_path != NULL)
	{
		ft_change_rep(new_path, e);
		return (1);
	}
	else
	{
		ft_putendl_fd("cd: missing key HOME", 2);
		return (0);
	}
}

void		ft_cd(char **cmd, t_env *e)
{
	if (ft_syntax_cd(cmd) == 2)
	{
		if (ft_strcmp(cmd[1], "-") == 0)
			ft_back_rep(e);
		else if (ft_strcmp(cmd[1], "~") == 0)
			ft_back_home(e);
		else
			ft_change_rep(cmd[1], e);
	}
	else if (ft_syntax_cd(cmd) == 1)
		ft_back_home(e);
}
