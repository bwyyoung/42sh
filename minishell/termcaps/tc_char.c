/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 16:36:02 by mda-cost          #+#    #+#             */
/*   Updated: 2016/06/01 16:36:47 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/termcaps.h"

void	tc_addchar(char *line, char c, int x)
{
	int		i;

	i = ft_strlen(line);
	line[i + 1] = '\0';
	while (i > x)
	{
		line[i] = line[i - 1];
		i--;
	}
	line[x] = c;
}

void	tc_delchar(char *line, int x)
{
	while (line[x] != '\0')
	{
		line[x] = line[x + 1];
		x++;
	}
	line[x] = '\0';
}

void	tc_fake_char(t_shell *sh)
{
	ft_putchar(' ');
	ft_putstr(sh->caps->go_left);
}

void	tc_insert_char(char *line, char *key, t_shell *sh)
{
	int		pos;
	int		n;

	n = 0;
	pos = (sh->x + (sh->y * sh->ws.ws_col)) - sh->prompt_len;
	if (ft_strlen(line) < 400)
	{
		if (sh->select == 1)
			tc_delete_selection(line, sh, sh->s_x);
		pos = (sh->x + (sh->y * sh->ws.ws_col)) - sh->prompt_len;
		tc_addchar(line, key[0], pos);
		ft_putstr(sh->caps->clear_lines);
		tc_print(&line[pos], sh, sh->caps);
		if (sh->y > 0 && sh->x == 0)
			tc_fake_char(sh);
		n = ft_strlen(line) - pos - 1;
		while (n > 0)
		{
			tc_cursor_left(line, sh, sh->caps);
			n--;
		}
	}
	else
		ft_putstr(sh->caps->ding);
}
