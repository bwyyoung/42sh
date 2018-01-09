/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 17:49:38 by mda-cost          #+#    #+#             */
/*   Updated: 2016/05/30 17:49:39 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"
#include "../include/parser.h"

static void	rm_spaces(char *str)
{
	int		i;

	i = 0;
	while (i < (ft_strlen(str) - 1) && str[i])
	{
		if (str[i] == '\t' || str[i] == '\b' || str[i] == '\n' ||
				str[i] == '\r' || str[i] == '\f')
			str[i] = ' ';
		i++;
	}
}

int			ft_add_history(char *line)
{
	int		fd;
	char	*history;

	history = NULL;
	if (line != NULL && ft_strlen(line) > 1 && line[0] != '\n')
	{
		if ((fd = open("/tmp/.history", O_WRONLY |
			O_APPEND | O_CREAT, 0644)) != -1)
		{
			history = ft_strdup(line);
			rm_spaces(history);
			ft_putstr_fd(history, fd);
			ft_freestr(history);
			close(fd);
			return (1);
		}
	}
	return (-1);
}
