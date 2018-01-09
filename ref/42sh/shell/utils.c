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

#include "../include/shell.h"

char		*ft_return_key(char *key, char **env, int len)
{
	int		i;

	i = 0;
	if (!env)
		return (NULL);
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
	if (!env)
		return (NULL);
	while (env[i] != NULL)
	{
		if (ft_strnequ(key, env[i], len) == 1)
			return (env[i] + len);
		i++;
	}
	return (NULL);
}

char		*ft_return_var(char *key, char **env, int len)
{
	int		i;

	i = 0;
	if (!env)
		return (NULL);
	while (env[i] != NULL)
	{
		if (ft_strnequ(key, env[i], len) == 1)
		{
			if (*(env[i] + len) == '=')
				return (env[i] + len + 1);
		}
		i++;
	}
	return (NULL);
}

int			ft_find_key(char *key_egal, char **env, int len_key)
{
	int		i;

	i = 0;
	if (!env)
		return (0);
	while (env && env[i])
	{
		if (ft_strnequ(key_egal, env[i], len_key) == 1)
			return (1);
		i++;
	}
	return (0);
}

void		ft_putarray_color(char **array)
{
	int	i;

	i = 0;
	if (array && array[i])
	{
		while (array[i] != NULL)
		{
			ft_putstr("[");
			ft_putnbr(i);
			ft_putstr("] ");
			ft_putendl_fd_color(array[i], 1, RED);
			i++;
		}
	}
}
