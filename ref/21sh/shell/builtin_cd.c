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

#include "../include/shell.h"

static int	cd_syntax(char **cmd)
{
	int		nb;

	nb = ft_tablen(cmd);
	if (nb > 2)
	{
		ft_putendl_fd("21sh: cd: Too many arguments", 2);
		return (-1);
	}
	else
		return (nb);
}

static void	cd_change_rep(char *direction, t_env *e)
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
}

static void	cd_back_rep(t_env *e)
{
	char	*new_path;

	new_path = ft_return_rep("OLDPWD=", e->env, 7);
	if (new_path != NULL)
		cd_change_rep(new_path, e);
	else
		ft_putendl_fd("cd: missing key OLDPWD", 2);
}

static void	cd_back_home(t_env *e)
{
	char	*new_path;

	new_path = ft_return_rep("HOME=", e->env, 5);
	if (new_path != NULL)
		cd_change_rep(new_path, e);
	else
		ft_putendl_fd("cd: missing key HOME", 2);
}

void		builtin_cd(t_env *e)
{
	int		ret;

	ret = cd_syntax(e->cmd);
	if (ret == 2)
	{
		if (ft_strcmp(e->cmd[1], "-") == 0)
			cd_back_rep(e);
		else if (ft_strcmp(e->cmd[1], "~") == 0)
			cd_back_home(e);
		else
			cd_change_rep(e->cmd[1], e);
	}
	else if (ret == 1)
		cd_back_home(e);
}
