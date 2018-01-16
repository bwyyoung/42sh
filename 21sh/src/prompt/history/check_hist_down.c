/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hist_down.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/12/25 07:29:01 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_sh.h"

void check_hist_down(t_line *line)
{
	t_hist *tmp_his;
	char *replacement;

	tmp_his = NULL;
	replacement = NULL;
	if (!line)
		fatal("Error (check_hist_down)");
	if (!line->history)
		return;
	if (line->his_index == 0)
		return;
	else if (get_last_index(line->history) == line->his_index)
		replacement = "";
	else
	{
		line->his_index++;
		tmp_his = line->history;
		while (tmp_his && tmp_his->index != line->his_index)
			tmp_his = tmp_his->next;
		replacement = tmp_his->cmd;
	}
	free_buffer(line->buffer);
	line->buffer = replace_buffer(replacement);
	set_cursor_internal(line);
}