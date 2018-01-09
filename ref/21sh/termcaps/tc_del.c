/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 16:37:42 by mda-cost          #+#    #+#             */
/*   Updated: 2016/06/01 16:37:46 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/termcaps.h"

void	tc_del_left(char *line, t_shell *sh, t_caps *caps)
{
	int		pos;

	pos = (sh->x + (sh->y * sh->ws.ws_col)) - sh->prompt_len;
	if (pos > 0 && ft_strlen(line) > 0)
	{
		if (sh->select == 1)
			tc_delete_selection(line, sh, sh->s_x);
		else
		{
			tc_cursor_left(line, sh, caps);
			tc_del_right(line, sh, caps);
		}
	}
}

void	tc_del_right(char *line, t_shell *sh, t_caps *caps)
{
	int		pos;

	pos = (sh->x + (sh->y * sh->ws.ws_col)) - sh->prompt_len;
	if (pos >= 0 && ft_strlen(line) > 0)
	{
		if (sh->select == 1)
			tc_delete_selection(line, sh, sh->s_x);
		else
		{
			tc_delchar(line, pos);
			ft_refresh(line, sh, caps);
		}
	}
}

void	tc_delete_selection(char *line, t_shell *sh, int x)
{
	while (x <= sh->s_y)
	{
		tc_delchar(line, x);
		sh->s_y--;
	}
	tc_unselect(line, sh, x);
}
