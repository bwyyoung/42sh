/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cursor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/12/25 07:29:01 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/ft_sh.h"

/*
** positions the cursor at its proper position
** according to the cursor linked list
*/

void set_cursor(t_line *line)
{
	t_cursor *tmp;

	tmp = NULL;
	if (!line || !line->cursor)
		fatal("Error (set_cursor)");
	tmp = line->cursor;
	reset_cursor();
	while (tmp->c_ind < line->current_c->c_ind)
	{
		tputs(tgetstr("nd", NULL), 0, putintc);
		tmp = tmp->next;
	}
}