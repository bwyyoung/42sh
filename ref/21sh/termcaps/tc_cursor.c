/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_cursor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 16:39:49 by mda-cost          #+#    #+#             */
/*   Updated: 2016/06/01 16:40:27 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/termcaps.h"

void	tc_move_right(char *line, t_shell *sh, t_caps *caps)
{
	int		pos;

	pos = (sh->x + (sh->y * sh->ws.ws_col)) - sh->prompt_len;
	if (pos < ft_strlen(line))
	{
		if (sh->select == 1)
			tc_unselect(line, sh, sh->s_y + 1);
		else
		{
			if (sh->x > 0 && (sh->x % (sh->ws.ws_col - 1) == 0))
			{
				ft_putstr(caps->go_down);
				sh->x = 0;
				sh->y++;
			}
			else
			{
				ft_putstr(caps->go_right);
				sh->x++;
			}
		}
	}
}

void	tc_move_left(char *line, t_shell *sh, t_caps *caps)
{
	int		pos;

	pos = (sh->x + (sh->y * sh->ws.ws_col)) - sh->prompt_len;
	if (pos > 0)
	{
		if (sh->select == 1)
			tc_unselect(line, sh, sh->s_x);
		else
		{
			ft_putstr(caps->go_left);
			if (sh->x == 0 && sh->y > 0)
			{
				sh->x = sh->ws.ws_col - 1;
				sh->y--;
			}
			else
				sh->x--;
		}
	}
}

void	tc_cursor_right(char *line, t_shell *sh, t_caps *caps)
{
	int		pos;

	pos = (sh->x + (sh->y * sh->ws.ws_col)) - sh->prompt_len;
	if (pos < ft_strlen(line))
	{
		if (sh->x > 0 && (sh->x % (sh->ws.ws_col - 1) == 0))
		{
			ft_putstr(caps->go_down);
			sh->x = 0;
			sh->y++;
		}
		else
		{
			ft_putstr(caps->go_right);
			sh->x++;
		}
	}
}

void	tc_cursor_left(char *line, t_shell *sh, t_caps *caps)
{
	int		pos;
	char	*useless;

	pos = (sh->x + (sh->y * sh->ws.ws_col)) - sh->prompt_len;
	if (pos > 0)
	{
		ft_putstr(caps->go_left);
		if (sh->x == 0 && sh->y > 0)
		{
			sh->x = sh->ws.ws_col - 1;
			sh->y--;
		}
		else
			sh->x--;
	}
	useless = line;
}
