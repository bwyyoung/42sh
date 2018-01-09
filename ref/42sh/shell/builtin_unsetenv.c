/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/19 16:16:19 by mda-cost          #+#    #+#             */
/*   Updated: 2015/04/20 16:45:04 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

static int	syntax_unsetenv(char **cmd)
{
	int		i;

	i = 1;
	while (cmd && cmd[i] != NULL)
	{
		if (ft_strchr(cmd[i], '='))
		{
			ft_putendl_fd("42sh: Syntax error", 2);
			return (0);
		}
		i++;
	}
	if (ft_tablen(cmd) < 2)
	{
		ft_putendl_fd("ft_minishell1: unsetenv: Too few arguments", 2);
		return (0);
	}
	return (1);
}

static char	**unsetenv_redo_env(t_env *e, char *key_egal, int len)
{
	int		i;
	int		j;
	char	**n_env;

	i = ft_tablen(e->env) + 1;
	if (!(n_env = (char **)malloc(sizeof(char *) * i)))
		ft_error("ft_unsetenv: malloc failed");
	i = 0;
	j = 0;
	while (e->env != NULL && e->env[i])
	{
		if (ft_strnequ(key_egal, e->env[i], len) == 0)
		{
			n_env[j] = ft_strdup(e->env[i]);
			j++;
		}
		i++;
	}
	n_env[j] = NULL;
	return (n_env);
}

void		ft_unsetenv(char *key, t_env *e)
{
	char	*key_egal;
	int		key_len;
	char	**tmp;

	key_egal = NULL;
	key_egal = ft_strjoin(key, "=");
	key_len = ft_strlen(key_egal);
	tmp = e->env;
	e->env = unsetenv_redo_env(e, key_egal, key_len);
	ft_arrayfree(tmp);
	ft_freestr(key_egal);
	tmp = NULL;
	key_egal = NULL;
}

void		builtin_unsetenv(t_env *e)
{
	int		i;

	i = 1;
	if (syntax_unsetenv(e->cmd) != 0)
	{
		while (e->env != NULL && e->cmd[i] != NULL)
		{
			ft_unsetenv(e->cmd[i], e);
			i++;
		}
	}
}
