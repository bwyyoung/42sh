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

#include "ft_sh.h"

int		ft_syntax_unsetenv(char **cmd)
{
	int		i;

	i = 1;
	while (cmd[i] != NULL)
	{
		if (ft_strchr(cmd[i], '='))
		{
			ft_putendl_fd("ft_minishell2: Syntax error", 2);
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

char	**ft_rebuild_env(t_env *e, char *key_egal, int len)
{
	int		i;
	int		j;
	char	**n_env;

	i = ft_tablen(e->env) + 1;
	if (!(n_env = (char **)malloc(sizeof(char *) * i)))
		ft_error("ft_unsetenv: malloc failed");
	i = 0;
	j = 0;
	while (e->env[i])
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

int		ft_unsetenv(char *key, t_env *e)
{
	char	*key_egal;
	int		key_len;
	char	**tmp;

	key_egal = NULL;
	key_egal = ft_strjoin(key, "=");
	key_len = ft_strlen(key_egal);
	tmp = e->env;
	e->env = ft_rebuild_env(e, key_egal, key_len);
	ft_freetab(tmp);
	ft_freestr(key_egal);
	tmp = NULL;
	key_egal = NULL;
	return (1);
}

int		ft_pre_unsetenv(char **cmd, t_env *e)
{
	int		i;

	i = 1;
	if (ft_syntax_unsetenv(cmd) != 1)
	{
		return (0);
	}
	else
	{
		while (cmd[i] != NULL)
		{
			ft_unsetenv(cmd[i], e);
			i++;
		}
		return (1);
	}
}
