/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 16:37:15 by mda-cost          #+#    #+#             */
/*   Updated: 2016/06/01 16:37:22 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/termcaps.h"

void	tc_end(char *line, t_shell *sh, t_caps *caps)
{
	int		pos;

	pos = (sh->x + (sh->y * sh->ws.ws_col)) - sh->prompt_len;
	if (sh->select == 1)
		tc_unselect(line, sh, pos);
	pos = (sh->x + (sh->y * sh->ws.ws_col)) - sh->prompt_len;
	while (pos < ft_strlen(line))
	{
		tc_cursor_right(line, sh, caps);
		pos = (sh->x + (sh->y * sh->ws.ws_col)) - sh->prompt_len;
	}
}
