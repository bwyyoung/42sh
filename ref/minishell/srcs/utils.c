/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/16 17:43:07 by mda-cost          #+#    #+#             */
/*   Updated: 2015/04/20 16:46:54 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void		*ft_freetab_and_null(char **tab)
{
	int		i;

	i = 0;
	if (tab != NULL)
	{
		while (tab[i] != NULL)
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
	return (NULL);
}

void		ft_print_test(char **tab)
{
	int		i;

	i = 0;
	if (tab == NULL)
		ft_putendl("the tab is NULL");
	else
	{
		while (tab[i])
		{
			ft_putendl(tab[i]);
			i++;
		}
	}
}

char		*ft_return_key(char *key, char **env, int len)
{
	int		i;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strnequ(key, env[i], len) == 1)
			return (env[i]);
		i++;
	}
	return (NULL);
}

char		*ft_return_rep(char *key, char **env, int len)
{
	int		i;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strnequ(key, env[i], len) == 1)
			return (env[i] + len);
		i++;
	}
	return (NULL);
}

int			ft_find_key(char *key_egal, char **env, int len_key)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strnequ(key_egal, env[i], len_key) == 1)
			return (1);
		i++;
	}
	return (0);
}
