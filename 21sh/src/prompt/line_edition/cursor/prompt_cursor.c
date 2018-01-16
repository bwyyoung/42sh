/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_cursor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/12/25 07:29:01 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/ft_sh.h"

/*
** resets the cursor to the beginnging of the prompt
*/

void prompt_cursor(t_line *line)
{
	int i;
	int prompt_len;

	i = 0;
	prompt_len = 0;
	if (!line || !line->prompt)
		fatal("Error: (reset_cursor)");
	prompt_len = ft_strlen(line->prompt);
	reset_cursor();
	while (i < prompt_len)
	{
		tputs(tgetstr("nd", NULL), 0, putintc);
		i++;
	}
	tputs(tgetstr("ce", NULL), 0, putintc);
}