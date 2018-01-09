/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 18:03:03 by mda-cost          #+#    #+#             */
/*   Updated: 2016/06/01 16:39:39 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"
#include "../include/parser.h"

t_hist		*ft_load_history(void)
{
	int		fd;
	char	*line;
	t_hist	*hist;

	line = NULL;
	hist = NULL;
	if ((fd = open("/tmp/.history", O_RDONLY)) != -1)
	{
		while (get_next_line(fd, &line) > 0)
		{
			if (ft_strlen(line) < 405)
				hist = ft_add_head_double(hist, line);
			free(line);
			line = NULL;
		}
		close(fd);
		hist = ft_add_head_double(hist, NULL);
	}
	return (hist);
}

void		tc_up(char *line, t_shell *sh, t_caps *caps)
{
	t_caps	*useless;

	if (sh->history && sh->history->next)
	{
		if (ft_strcmp(line, sh->history->cmd) != 0)
		{
			ft_bzero(sh->history->cmd, LINE_SIZE);
			ft_strcpy(sh->history->cmd, line);
		}
		sh->history = sh->history->next;
		tc_home(line, sh, sh->caps);
		ft_bzero(line, LINE_SIZE);
		ft_strcpy(line, sh->history->cmd);
		tc_unselect(line, sh, ft_strlen(line) + 500);
	}
	useless = caps;
}

void		tc_down(char *line, t_shell *sh, t_caps *caps)
{
	t_caps	*useless;

	if (sh->history && sh->history->prev)
	{
		if (ft_strcmp(line, sh->history->cmd) != 0)
		{
			ft_bzero(sh->history->cmd, LINE_SIZE);
			ft_strcpy(sh->history->cmd, line);
		}
		sh->history = sh->history->prev;
		tc_home(line, sh, sh->caps);
		ft_bzero(line, LINE_SIZE);
		ft_strcpy(line, sh->history->cmd);
		tc_unselect(line, sh, ft_strlen(line) + 500);
	}
	useless = caps;
}
