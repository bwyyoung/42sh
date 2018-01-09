/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 18:49:03 by mda-cost          #+#    #+#             */
/*   Updated: 2016/06/01 16:00:32 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	ft_signal_stop(int i)
{
	t_info			*info;

	info = ft_global(NULL);
	write(1, "\n", 1);
	if (info)
	{
		if (info->sh)
		{
			if (info->sh->exec == 0)
			{
				if (info->sh->line)
					ft_bzero(info->sh->line, ft_strlen(info->sh->line));
				info->sh->x = 0;
				info->sh->y = 0;
				info->sh->s_x = 0;
				info->sh->s_y = 0;
				info->sh->select = 0;
				ft_putstr_fd_color(info->sh->prompt, 1, YELLOW);
				info->sh->x = ft_strlen(info->sh->prompt);
			}
		}
	}
	(void)i;
}

void	ft_signal_resize(int i)
{
	t_info			*info;

	info = ft_global(NULL);
	if (info)
	{
		if (info->sh)
		{
			if (info->sh->line)
				tc_home(info->sh->line, info->sh, info->sh->caps);
			ioctl(0, TIOCGWINSZ, &info->sh->ws);
			ft_putstr(info->sh->caps->clear_lines);
			ft_putstr(info->sh->caps->go_up);
			ft_putstr(info->sh->caps->go_down);
			ft_putstr_fd_color(info->sh->prompt, 1, YELLOW);
			info->sh->x = ft_strlen(info->sh->prompt);
			tc_print(info->sh->line, info->sh, info->sh->caps);
			if (info->sh->y > 0 && info->sh->x == 0)
				tc_fake_char(info->sh);
		}
	}
	(void)i;
}

void	ft_signal(void)
{
	signal(SIGINT, ft_signal_stop);
	signal(SIGWINCH, ft_signal_resize);
}

t_info	*ft_global(t_info *info)
{
	static t_info *save;

	if (info)
		save = info;
	return (save);
}
