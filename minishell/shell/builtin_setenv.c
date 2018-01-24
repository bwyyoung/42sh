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

#include "../include/parser.h"

static char	**setenv_redo_env(char *key_egal, char *value, t_env *e)
{
	char	**n_env;
	int		i;

	i = ft_tablen(e->env) + 2;
	if (!(n_env = (char **)malloc(sizeof(char *) * i)))
		ft_error("ft_setenv: malloc failed");
	i = 0;
	while (e->env != NULL && e->env[i])
	{
		n_env[i] = ft_strdup(e->env[i]);
		i++;
	}
	ft_arrayfree(e->env);
	e->env = NULL;
	n_env[i] = ft_strjoin(key_egal, value);
	n_env[i + 1] = NULL;
	return (n_env);
}

static void	setenv_addkey(char *key_egal, char *val, t_env *e, int len)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	while (e->env != NULL && e->env[i])
	{
		if (ft_strnequ(key_egal, e->env[i], len) == 1)
		{
			tmp = e->env[i];
			e->env[i] = ft_strjoin(key_egal, val);
			ft_freestr(tmp);
		}
		i++;
	}
}

void		ft_setenv(char *key, char *value, t_env *e)
{
	int		len_key;
	char	*key_egal;

	key_egal = ft_strjoin(key, "=");
	len_key = ft_strlen(key_egal);
	if (ft_find_key(key_egal, e->env, len_key) == 0)
		e->env = setenv_redo_env(key_egal, value, e);
	else
		setenv_addkey(key_egal, value, e, len_key);
	ft_freestr(key_egal);
}

void		builtin_setenv(t_env *e)
{
	if (syntax_setenv(e->cmd) != 0)
		ft_setenv(e->cmd[1], e->cmd[2], e);
}
