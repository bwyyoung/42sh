/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/17 11:08:11 by mda-cost          #+#    #+#             */
/*   Updated: 2015/04/20 16:46:43 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void		ft_cmd_line(char *cmd_line, t_env *e)
{
	cmd_line = ft_del_tab(cmd_line);
	e->cmd = ft_strsplit(cmd_line, ' ');
	if (e->cmd[0] != NULL)
		ft_is_builtin_or_not(e->cmd, e);
	ft_freetab(e->cmd);
	ft_freetab(e->paths);
	e->cmd = NULL;
	e->paths = NULL;
}

char		*ft_del_tab(char *cmd)
{
	int		i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\t')
			cmd[i] = ' ';
		i++;
	}
	return (cmd);
}

void		ft_start(t_env *e)
{
	char	*line;
	char	**tab;
	int		i;

	while (42)
	{
		ft_prompt(e);
		line = NULL;
		tab = NULL;
		if (get_next_line(0, &line) > 0)
		{
			tab = ft_strsplit(line, ';');
			ft_freestr(line);
			i = 0;
			while (tab[i])
			{
				ft_cmd_line(tab[i], e);
				i++;
			}
			ft_freetab(tab);
		}
		else
			ft_error("bad input");
	}
}
