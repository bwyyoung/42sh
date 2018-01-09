/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 17:56:57 by mda-cost          #+#    #+#             */
/*   Updated: 2015/04/20 16:44:53 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char	**ft_redo_env(char *key_egal, char *value, t_env *e)
{
	char	**n_env;
	int		i;

	i = ft_tablen(e->env) + 2;
	if (!(n_env = (char **)malloc(sizeof(char *) * i)))
		ft_error("ft_setenv: malloc failed");
	i = 0;
	while (e->env[i])
	{
		n_env[i] = ft_strdup(e->env[i]);
		i++;
	}
	ft_freetab(e->env);
	e->env = NULL;
	n_env[i] = ft_strjoin(key_egal, value);
	n_env[i + 1] = NULL;
	return (n_env);
}

int		ft_add_value_env(char *key_egal, char *val, t_env *e, int len)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	while (e->env[i])
	{
		if (ft_strnequ(key_egal, e->env[i], len) == 1)
		{
			tmp = e->env[i];
			e->env[i] = ft_strjoin(key_egal, val);
			ft_freestr(tmp);
			return (1);
		}
		i++;
	}
	return (0);
}

int		ft_setenv(char *key, char *value, t_env *e)
{
	int		len_key;
	char	*key_egal;

	key_egal = ft_strjoin(key, "=");
	len_key = ft_strlen(key_egal);
	if (ft_find_key(key_egal, e->env, len_key) == 0)
	{
		e->env = ft_redo_env(key_egal, value, e);
		return (1);
	}
	else
	{
		ft_add_value_env(key_egal, value, e, len_key);
	}
	ft_freestr(key_egal);
	return (1);
}

int		ft_syntax_setenv(char **cmd)
{
	int		i;

	i = 1;
	while (cmd[i])
	{
		if (ft_strchr(cmd[i], '='))
		{
			ft_putendl_fd("ft_minishell2: Syntax error", 2);
			return (0);
		}
		i++;
	}
	if (ft_tablen(cmd) > 3)
	{
		ft_putendl_fd("ft_minishell2: Too many arguments", 2);
		return (0);
	}
	if (ft_tablen(cmd) < 3)
	{
		ft_putendl_fd("ft_minishell2: Too few arguments", 2);
		return (0);
	}
	return (1);
}

int		ft_pre_setenv(char **cmd, t_env *e)
{
	if (ft_syntax_setenv(cmd) != 1)
	{
		return (0);
	}
	else
	{
		ft_setenv(cmd[1], cmd[2], e);
		return (1);
	}
}
