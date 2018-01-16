/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cur_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/12/25 07:29:01 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/ft_sh.h"

/*
** returns a pointer to the
** buffer element which is found at
** the current tracked cursor position
*/

t_buf *get_cur_buffer(t_line *line)
{
	t_buf *ret;
	t_cursor *tmp_cur;

	ret = NULL;
	tmp_cur = NULL;
	if (!line || !line->first_c || !line->current_c)
		fatal("Error (get_cur_buffer)");
	ret = line->buffer;
	tmp_cur = line->first_c;
	while (ret->next && tmp_cur->next &&
		tmp_cur->c_ind != line->current_c->c_ind)
	{
		ret = ret->next;
		tmp_cur = tmp_cur->next;
	}
	return (ret);
}
