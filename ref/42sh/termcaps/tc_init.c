/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 16:44:37 by mda-cost          #+#    #+#             */
/*   Updated: 2016/06/01 16:44:39 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

static void		ft_array_tc(t_shell *sh)
{
	sh->tab_key[0] = NULL;
	sh->tab_key[1] = tc_up;
	sh->tab_key[2] = tc_down;
	sh->tab_key[3] = tc_move_right;
	sh->tab_key[4] = tc_move_left;
	sh->tab_key[5] = tc_end;
	sh->tab_key[6] = tc_home;
	sh->tab_key[7] = tc_shift_down;
	sh->tab_key[8] = tc_shift_up;
	sh->tab_key[9] = tc_alt_right;
	sh->tab_key[10] = tc_alt_left;
	sh->tab_key[11] = tc_enter;
	sh->tab_key[12] = tc_del_right;
	sh->tab_key[13] = tc_del_left;
	sh->tab_key[14] = tc_shift_right;
	sh->tab_key[15] = tc_shift_left;
	sh->tab_key[16] = tc_copy;
	sh->tab_key[17] = tc_paste;
	sh->tab_key[18] = tc_cut;
	sh->tab_key[19] = NULL;
	sh->tab_key[20] = NULL;
}

static t_caps	*ft_termcaps_loader(void)
{
	t_caps	*caps;

	if (!(caps = (t_caps *)malloc(sizeof(t_caps))))
		return (NULL);
	caps->go_right = tgetstr("nd", NULL);
	caps->go_left = tgetstr("le", NULL);
	caps->go_up = tgetstr("up", NULL);
	caps->go_down = tgetstr("do", NULL);
	caps->go_home = tgetstr("cr", NULL);
	caps->go_to_x = tgetstr("ch", NULL);
	caps->delete = tgetstr("dc", NULL);
	caps->insert_mode = tgetstr("im", NULL);
	caps->leave_insert = tgetstr("ei", NULL);
	caps->go_standout = tgetstr("so", NULL);
	caps->leave_standout = tgetstr("se", NULL);
	caps->clear_lines = tgetstr("cd", NULL);
	caps->ding = tgetstr("bl", NULL);
	return (caps);
}

t_shell			*ft_shell_malloc(void)
{
	t_shell	*sh;

	sh = NULL;
	if (!(sh = (t_shell *)malloc(sizeof(t_shell))))
		return (NULL);
	ft_bzero((void *)sh, sizeof(t_shell));
	sh->line = ft_strnew(LINE_SIZE);
	sh->prompt = ft_strdup("> ");
	sh->prompt_len = ft_strlen(sh->prompt);
	sh->caps = ft_termcaps_loader();
	ioctl(0, TIOCGWINSZ, &sh->ws);
	sh->copybuff = ft_strnew(LINE_SIZE);
	sh->history = ft_load_history();
	ft_array_tc(sh);
	return (sh);
}
