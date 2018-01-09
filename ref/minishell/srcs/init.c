/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/16 17:27:07 by mda-cost          #+#    #+#             */
/*   Updated: 2015/04/20 16:46:14 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void		ft_shell_lvl(t_env *e)
{
	int		i;
	char	*ptr;
	char	*lvl;

	i = 0;
	ptr = NULL;
	lvl = NULL;
	if (ft_find_key("SHLVL=", e->env, 6) == 1)
	{
		ptr = ft_return_rep("SHLVL=", e->env, 6);
		i = ft_atoi(ptr);
		i++;
		lvl = ft_itoa(i);
		ft_setenv("SHLVL", lvl, e);
		ptr = NULL;
		lvl = NULL;
	}
}

char		**ft_rescue_env(void)
{
	char	**str;
	char	*pwd;

	str = NULL;
	str = (char**)malloc(sizeof(char *) * 5);
	pwd = getcwd(NULL, 1024);
	str[0] = ft_strdup("PATH=/bin:/usr/bin");
	str[1] = ft_strdup("HOME=");
	str[1] = ft_strjoin(str[1], pwd);
	str[2] = ft_strdup("PWD=");
	str[2] = ft_strjoin(str[2], pwd);
	str[3] = ft_strdup("OLDPWD=");
	str[3] = ft_strjoin(str[3], pwd);
	str[4] = NULL;
	free(pwd);
	return (str);
}

char		**ft_copyenv(char **environ)
{
	int		i;
	char	**tab;

	i = 0;
	tab = NULL;
	while (environ[i] != NULL)
		i++;
	if (i == 0)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = 0;
	while (environ[i] != NULL)
	{
		tab[i] = ft_strdup(environ[i]);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

t_env		*ft_init_env(t_env *e, char **environ)
{
	if (!(e = (t_env*)malloc(sizeof(t_env))))
		ft_error("ft_init_env: malloc failed");
	e->env = NULL;
	e->cmd = NULL;
	e->paths = NULL;
	if (environ[0] != NULL)
		e->env = ft_copyenv(environ);
	else
		e->env = ft_rescue_env();
	if (ft_check_env(e->env) == 0)
	{
		ft_error("ft_init_env: bad env");
	}
	ft_shell_lvl(e);
	ft_start(e);
	return (e);
}
