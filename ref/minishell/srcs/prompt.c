/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/16 16:57:49 by mda-cost          #+#    #+#             */
/*   Updated: 2015/04/20 16:46:36 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void		ft_print_pwd_prompt(char *line)
{
	int		i;
	char	**tab;

	i = 0;
	tab = NULL;
	tab = ft_strsplit(line, '/');
	while (tab && tab[i] != NULL)
		i++;
	if (tab[i - 1] && (ft_strlen(tab[i - 1]) > 0))
	{
		if (ft_strlen(tab[i - 1]) == 4 && ft_strnequ("PWD=", tab[i - 1], 4))
		{
			ft_putstr("\033[0;33;40m");
			ft_putstr("/");
			ft_putstr("\033[0m");
		}
		else
		{
			ft_putstr("\033[0;33;40m");
			ft_putstr(tab[i - 1]);
			ft_putstr("\033[0m");
		}
	}
	ft_putstr(" > ");
	ft_freetab(tab);
}

void		ft_prompt(t_env *e)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	ft_putstr("$ ");
	if (ft_find_key("PWD=", e->env, 4) == 1)
	{
		if ((line = ft_return_key("PWD=", e->env, 4)) != NULL)
		{
			if (ft_strlen(line) > 4)
			{
				ft_print_pwd_prompt(line);
			}
		}
	}
}
