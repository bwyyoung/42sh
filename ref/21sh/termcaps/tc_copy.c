/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_copy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 20:30:34 by mda-cost          #+#    #+#             */
/*   Updated: 2016/06/01 16:37:04 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/termcaps.h"

void	tc_copy(char *line, t_shell *sh, t_caps *caps)
{
	int			length;
	t_caps		*useless;

	length = (sh->s_y - sh->s_x) + 1;
	if (sh->select == 1)
	{
		ft_bzero(sh->copybuff, LINE_SIZE);
		ft_strncpy(sh->copybuff, &line[sh->s_x], length);
	}
	useless = caps;
}

void	tc_paste(char *line, t_shell *sh, t_caps *caps)
{
	int			i;
	int			pos;

	if (ft_strlen(line) < 400)
	{
		pos = (sh->x + (sh->y * sh->ws.ws_col)) - sh->prompt_len;
		if (ft_strlen(sh->copybuff) > 0)
		{
			i = 0;
			while (sh->copybuff[i])
			{
				tc_insert_char(line, &sh->copybuff[i], sh);
				i++;
			}
			pos = (sh->x + (sh->y * sh->ws.ws_col)) - sh->prompt_len;
		}
	}
	else
		ft_putstr(caps->ding);
}

void	tc_cut(char *line, t_shell *sh, t_caps *caps)
{
	int		i;
	int		pos;

	pos = (sh->x + (sh->y * sh->ws.ws_col)) - sh->prompt_len;
	i = sh->s_x;
	if (sh->select == 1)
	{
		tc_copy(line, sh, caps);
		while (i <= sh->s_y)
		{
			tc_delchar(line, i);
			sh->s_y--;
		}
		tc_unselect(line, sh, sh->s_x);
		sh->select = 0;
	}
}
