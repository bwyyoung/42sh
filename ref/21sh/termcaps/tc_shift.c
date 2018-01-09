/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_shift.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 16:45:04 by mda-cost          #+#    #+#             */
/*   Updated: 2016/06/01 16:43:27 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/termcaps.h"

static void	tc_shift_cross(char *line, t_shell *sh, int side)
{
	int		pos;

	pos = (sh->x + (sh->y * sh->ws.ws_col)) - sh->prompt_len;
	if (side == CROSS_RIGHT)
	{
		ft_putstr(sh->caps->leave_standout);
		ft_putchar(line[pos]);
		ft_putstr(sh->caps->go_left);
		tc_cursor_right(line, sh, sh->caps);
		pos = (sh->x + (sh->y * sh->ws.ws_col)) - sh->prompt_len;
		sh->s_x = pos;
	}
	else if (side == CROSS_LEFT)
	{
		ft_putstr(sh->caps->leave_standout);
		ft_putchar(line[pos]);
		ft_putstr(sh->caps->go_left);
		tc_cursor_right(line, sh, sh->caps);
		tc_cursor_left(line, sh, sh->caps);
		pos = (sh->x + (sh->y * sh->ws.ws_col)) - sh->prompt_len;
		sh->s_y = pos;
		if (sh->s_y == sh->s_x)
			sh->select = 0;
	}
}

void		tc_shift_right(char *line, t_shell *sh, t_caps *caps)
{
	int		pos;
	char	c;

	pos = (sh->x + (sh->y * sh->ws.ws_col)) - sh->prompt_len;
	if (pos >= 0 && pos < ft_strlen(line))
	{
		if (sh->select == 0)
			sh->s_x = pos;
		if (sh->select == 1 && sh->s_y > pos)
			tc_shift_cross(line, sh, CROSS_RIGHT);
		else
		{
			sh->select = 1;
			sh->s_y = pos;
			c = line[pos];
			ft_putstr(caps->go_standout);
			ft_putchar(c);
			ft_putstr(caps->leave_standout);
			ft_putstr(caps->go_left);
			tc_cursor_right(line, sh, caps);
		}
	}
}

void		tc_shift_left(char *line, t_shell *sh, t_caps *caps)
{
	int		pos;

	pos = (sh->x + (sh->y * sh->ws.ws_col)) - sh->prompt_len;
	if (pos >= 1 && pos <= ft_strlen(line))
	{
		tc_cursor_left(line, sh, caps);
		pos = (sh->x + (sh->y * sh->ws.ws_col)) - sh->prompt_len;
		if (sh->select == 0)
			sh->s_y = pos;
		if (sh->select == 1 && sh->s_x <= pos)
			tc_shift_cross(line, sh, CROSS_LEFT);
		else
		{
			sh->select = 1;
			sh->s_x = pos;
			ft_putstr(caps->go_standout);
			ft_putchar(line[pos]);
			ft_putstr(caps->leave_standout);
			ft_putstr(caps->go_left);
			tc_cursor_right(line, sh, caps);
			tc_cursor_left(line, sh, caps);
		}
	}
}

void		tc_shift_up(char *line, t_shell *sh, t_caps *caps)
{
	int		pos;
	int		n;

	n = sh->ws.ws_col;
	pos = (sh->x + (sh->y * sh->ws.ws_col)) - sh->prompt_len;
	if (sh->select == 1)
		tc_unselect(line, sh, pos);
	pos = (sh->x + (sh->y * sh->ws.ws_col)) - sh->prompt_len;
	if (sh->y > 0 && pos >= sh->ws.ws_col)
	{
		while (n > 0)
		{
			tc_cursor_left(line, sh, caps);
			n--;
		}
	}
}

void		tc_shift_down(char *line, t_shell *sh, t_caps *caps)
{
	int		pos;
	int		n;

	n = sh->ws.ws_col;
	pos = (sh->x + (sh->y * sh->ws.ws_col)) - sh->prompt_len;
	if (sh->select == 1)
		tc_unselect(line, sh, pos);
	pos = (sh->x + (sh->y * sh->ws.ws_col)) - sh->prompt_len;
	if (ft_strlen(&line[pos]) >= sh->ws.ws_col)
	{
		while (n > 0)
		{
			tc_cursor_right(line, sh, caps);
			n--;
		}
	}
}
