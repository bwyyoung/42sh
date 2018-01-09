/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_refresh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 16:40:54 by mda-cost          #+#    #+#             */
/*   Updated: 2016/06/01 16:41:29 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/termcaps.h"

void	ft_refresh(char *line, t_shell *sh, t_caps *caps)
{
	int		pos;
	int		n;

	pos = (sh->x + (sh->y * sh->ws.ws_col)) - sh->prompt_len;
	n = 0;
	ft_putstr(caps->clear_lines);
	tc_print(&line[pos], sh, caps);
	if (sh->y > 0 && sh->x == 0)
		tc_fake_char(sh);
	n = ft_strlen(line) - pos;
	while (n > 0)
	{
		tc_cursor_left(line, sh, caps);
		n--;
	}
}

void	tc_print(char *line, t_shell *sh, t_caps *caps)
{
	int		i;
	t_caps	*useless;

	i = 0;
	while (line[i])
	{
		ft_putchar(line[i]);
		if (sh->x > 0 && (sh->x % (sh->ws.ws_col - 1) == 0))
		{
			sh->x = 0;
			sh->y++;
		}
		else
			sh->x++;
		i++;
	}
	useless = caps;
}

void	tc_char_print(char *line, t_shell *sh, t_caps *caps)
{
	int		i;
	t_caps	*useless;

	i = 0;
	if (line[i])
	{
		ft_putchar(line[i]);
		if (sh->x > 0 && (sh->x % (sh->ws.ws_col - 1) == 0))
		{
			sh->x = 0;
			sh->y++;
		}
		else
			sh->x++;
		i++;
	}
	useless = caps;
}
