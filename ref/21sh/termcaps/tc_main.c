/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 16:49:35 by mda-cost          #+#    #+#             */
/*   Updated: 2016/06/01 16:49:38 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/termcaps.h"

static void	ft_check_length(t_shell *sh)
{
	if (ft_strlen(sh->line) > 600)
	{
		write(1, "\n", 1);
		ft_putendl_fd_color("command line too long, abort", 2, RED);
		ft_bzero(sh->line, sizeof(char) * ft_strlen(sh->line));
		sh->line[0] = '\n';
	}
}

int			tc_keydetect(char *key)
{
	int		action;

	action = 0;
	action = (ft_strcmp(key, UP)) ? action : 1;
	action = (ft_strcmp(key, DOWN)) ? action : 2;
	action = (ft_strcmp(key, RIGHT)) ? action : 3;
	action = (ft_strcmp(key, LEFT)) ? action : 4;
	action = (ft_strcmp(key, END)) ? action : 5;
	action = (ft_strcmp(key, HOME)) ? action : 6;
	action = (ft_strcmp(key, SHIFT_DOWN)) ? action : 7;
	action = (ft_strcmp(key, SHIFT_UP)) ? action : 8;
	action = (ft_strcmp(key, ALT_RIGHT)) ? action : 9;
	action = (ft_strcmp(key, ALT_LEFT)) ? action : 10;
	action = (ft_strcmp(key, ENTER)) ? action : 11;
	action = (ft_strcmp(key, DEL_RIGHT)) ? action : 12;
	action = (ft_strcmp(key, DEL_LEFT)) ? action : 13;
	action = (ft_strcmp(key, SHIFT_RIGHT)) ? action : 14;
	action = (ft_strcmp(key, SHIFT_LEFT)) ? action : 15;
	action = (ft_strcmp(key, ALT_C)) ? action : 16;
	action = (ft_strcmp(key, ALT_V)) ? action : 17;
	action = (ft_strcmp(key, ALT_X)) ? action : 18;
	return (action);
}

int			ft_termcaps_get_line(char *line, t_shell *sh)
{
	char	key[8];
	int		action;

	ft_putstr_fd_color(sh->prompt, 1, YELLOW);
	sh->x = ft_strlen(sh->prompt);
	while (ft_strchr(line, '\n') == NULL)
	{
		ft_bzero(key, 8);
		read(0, key, 8);
		if ((action = tc_keydetect(key)) > 0)
		{
			(*sh->tab_key[action])(line, sh, sh->caps);
			ft_check_length(sh);
			continue ;
		}
		if (!key[1] && !key[2] && !key[3] && ft_isprint(key[0]))
			tc_insert_char(line, key, sh);
		if (!key[1] && !key[2] && !key[3] && key[0] == 4
			&& ft_ctrl_d(line, sh) && ft_strlen(line) == 0)
			return (0);
		ft_check_length(sh);
	}
	return (1);
}
