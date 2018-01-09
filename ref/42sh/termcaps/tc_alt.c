/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_alt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 17:34:00 by mda-cost          #+#    #+#             */
/*   Updated: 2016/05/24 17:34:02 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/termcaps.h"

void	tc_alt_right(char *line, t_shell *sh, t_caps *caps)
{
	int		pos;

	pos = (sh->x + (sh->y * sh->ws.ws_col)) - sh->prompt_len;
	ft_check_unselect(line, sh, pos);
	pos = (sh->x + (sh->y * sh->ws.ws_col)) - sh->prompt_len;
	if (pos < ft_strlen(line))
	{
		while (pos < ft_strlen(line) && line[pos] == ' ')
		{
			tc_cursor_right(line, sh, caps);
			pos = (sh->x + (sh->y * sh->ws.ws_col)) - sh->prompt_len;
		}
		while (pos < ft_strlen(line) && ft_isalnum(line[pos]))
		{
			tc_cursor_right(line, sh, caps);
			pos = (sh->x + (sh->y * sh->ws.ws_col)) - sh->prompt_len;
		}
	}
}

void	tc_alt_left(char *line, t_shell *sh, t_caps *caps)
{
	int		pos;

	pos = (sh->x + (sh->y * sh->ws.ws_col)) - sh->prompt_len;
	ft_check_unselect(line, sh, pos);
	pos = (sh->x + (sh->y * sh->ws.ws_col)) - sh->prompt_len;
	if (pos > 0)
	{
		if (ft_isalnum(line[pos]))
		{
			tc_cursor_left(line, sh, caps);
			pos = (sh->x + (sh->y * sh->ws.ws_col)) - sh->prompt_len;
		}
		while (pos > 0 && (ft_isalnum(line[pos]) == 0))
		{
			tc_cursor_left(line, sh, caps);
			pos = (sh->x + (sh->y * sh->ws.ws_col)) - sh->prompt_len;
		}
		while (pos > 0 && ft_isalnum(line[pos]))
		{
			tc_cursor_left(line, sh, caps);
			pos = (sh->x + (sh->y * sh->ws.ws_col)) - sh->prompt_len;
		}
		if (pos >= 0 && (ft_isalnum(line[pos]) == 0))
			tc_cursor_right(line, sh, caps);
	}
}
