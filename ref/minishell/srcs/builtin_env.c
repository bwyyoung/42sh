/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 17:24:26 by mda-cost          #+#    #+#             */
/*   Updated: 2015/04/20 17:24:28 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char	**ft_tabdup(char **env, int len)
{
	int		i;
	char	**n_tab;

	i = 0;
	if (env == NULL)
	{
		n_tab = (char **)malloc(sizeof(char *) * (len + 1));
		n_tab[len] = NULL;
	}
	else
	{
		if (!(n_tab = (char **)malloc(sizeof(char *) * (len + 1))))
			ft_error("ft_tabdup: malloc failed");
		while (env[i])
		{
			n_tab[i] = ft_strdup(env[i]);
			i++;
		}
		n_tab[i] = NULL;
	}
	return (n_tab);
}

char	**ft_env_add_tmp(char **env, char *s)
{
	char	*var;
	char	*tmp;
	char	**tab;
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
		tab = ft_tabdup(env, ft_tablen(env) + 1);
		tab[ft_tablen(env)] = ft_strdup(s);
		tab[ft_tablen(env) + 1] = NULL;
		env = ft_freetab_and_null(env);
		return (tab);
	}
}

char	**ft_only_cmd(char **cmd, t_env *e, int i)
{
	int		size;
	int		j;
	char	**n_cmd;

	j = 0;
	size = ft_tablen(cmd);
	if (!(n_cmd = (char **)malloc(sizeof(char *) * (size - i + 1))))
		ft_error("ft_only_cmd: malloc failed");
	while (cmd[i + j])
	{
		n_cmd[j] = ft_strdup(cmd[i + j]);
		j++;
	}
	n_cmd[j] = NULL;
	ft_freetab(cmd);
	cmd = NULL;
	e->cmd = n_cmd;
	return (n_cmd);
}

void	ft_env_var_tmp(char **cmd, t_env *e, int i)
{
	char	*pos;

	while (cmd[i] && (pos = ft_strchr(cmd[i], '=')))
	{
		e->env = ft_env_add_tmp(e->env, cmd[i]);
		i++;
	}
	if (!cmd[i])
		ft_print_test(e->env);
	else
	{
		cmd = ft_only_cmd(cmd, e, i);
		ft_prepare(cmd, e);
	}
}

void	ft_builtin_env(char **cmd, t_env *e)
{
	char	**save;

	save = e->env;
	e->env = ft_tabdup(e->env, ft_tablen(e->env));
	if (ft_strcmp(cmd[1], "-i") == 0)
	{
		ft_freetab(e->env);
		e->env = NULL;
		ft_env_var_tmp(cmd, e, 2);
	}
	else
		ft_env_var_tmp(cmd, e, 1);
	ft_freetab(e->env);
	e->env = save;
}
