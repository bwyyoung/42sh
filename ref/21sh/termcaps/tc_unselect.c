/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_unselect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 16:41:51 by mda-cost          #+#    #+#             */
/*   Updated: 2016/06/01 16:41:52 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/termcaps.h"

void	tc_unselect(char *line, t_shell *sh, int x)
{
	sh->select = 0;
	sh->s_x = 0;
	sh->s_y = 0;
	tc_full_refresh(line, sh, x);
}

void	tc_full_refresh(char *line, t_shell *sh, int x)
{
	int		pos;

	pos = (sh->x + (sh->y * sh->ws.ws_col)) - sh->prompt_len;
	while (pos > 0)
	{
		tc_cursor_left(line, sh, sh->caps);
		pos = (sh->x + (sh->y * sh->ws.ws_col)) - sh->prompt_len;
	}
	ft_putstr(sh->caps->clear_lines);
	tc_print(line, sh, sh->caps);
	if (sh->y > 0 && sh->x == 0)
		tc_fake_char(sh);
	pos = (sh->x + (sh->y * sh->ws.ws_col)) - sh->prompt_len;
	while (pos > x)
	{
		tc_cursor_left(line, sh, sh->caps);
		pos = (sh->x + (sh->y * sh->ws.ws_col)) - sh->prompt_len;
	}
}

void	ft_check_unselect(char *line, t_shell *sh, int x)
{
	if (sh->select == 1)
		tc_unselect(line, sh, x);
}
