/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:46:10 by mda-cost          #+#    #+#             */
/*   Updated: 2016/11/07 19:46:13 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

static char	**env_duplicate(char **env, int len)
{
	int		i;
	char	**n_tab;

	i = 0;
	n_tab = NULL;
	if (!(n_tab = (char **)malloc(sizeof(char *) * (len + 1))))
		ft_error("env_duplicate: malloc failed");
	ft_bzero((void *)n_tab, sizeof(char *) * (len + 1));
	while (env && env[i])
	{
		n_tab[i] = ft_strdup(env[i]);
		i++;
	}
	n_tab[i] = NULL;
	return (n_tab);
}

char		**env_add_tmp(char **env, char *s)
{
	char	*var;
	char	*tmp;
	char	**array;
	int		i;

	i = 0;
	var = ft_strsub(s, 0, ft_strlen(s) - ft_strlen(ft_strchr(s, '=')));
	while (env && env[i] && ft_strncmp(env[i], var, ft_strlen(var)))
		i++;
	ft_freestr(var);
	if (env && env[i])
	{
		tmp = env[i];
		env[i] = ft_strdup(s);
		ft_freestr(tmp);
		return (env);
	}
	else
	{
		array = env_duplicate(env, ft_tablen(env) + 1);
		array[ft_tablen(env)] = ft_strdup(s);
		array[ft_tablen(env) + 1] = NULL;
		ft_arrayfree(env);
		return (array);
	}
}
