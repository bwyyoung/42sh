/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 15:38:50 by mda-cost          #+#    #+#             */
/*   Updated: 2015/01/19 16:39:36 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		end_line(char **line, char **buf)
{
	if (**buf)
	{
		*line = *buf;
		*buf = NULL;
		return (1);
	}
	return (0);
}

static int		get_line(int fd, char **line, char **buf)
{
	char		buffer[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[ret] = '\0';
		if (ret == -1)
			return (-1);
		if ((tmp = ft_strchr(buffer, '\n')))
		{
			*tmp = '\0';
			if ((*line = ft_strjoin(*buf, buffer)) == NULL
				|| (tmp = ft_strdup(tmp + 1)) == NULL)
				return (-1);
			free(*buf);
			*buf = tmp;
			return (1);
		}
		if ((tmp = ft_strjoin(*buf, buffer)) == NULL)
			return (-1);
		free(*buf);
		*buf = tmp;
	}
	return (end_line(line, buf));
}

int				get_next_line(int fd, char **line)
{
	static char	*buf;
	char		*tmp;

	if (BUFF_SIZE <= 0 || !line || fd < 0)
		return (-1);
	if (buf)
	{
		if ((tmp = ft_strchr(buf, '\n')))
		{
			*tmp = '\0';
			if ((*line = ft_strdup(buf)) == NULL
				|| (tmp = ft_strdup(tmp + 1)) == NULL)
				return (-1);
			free(buf);
			buf = tmp;
			return (1);
		}
	}
	else
	{
		if ((buf = (char *)malloc(sizeof(char))) == NULL)
			return (-1);
		*buf = '\0';
	}
	return (get_line(fd, line, &buf));
}
