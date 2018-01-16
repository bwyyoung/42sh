/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/12/25 07:29:01 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_sh.h"

/*
** iterates through an entire list
** and finds out the length of it
*/

int list_len(t_buf *buffer)
{
	int i;
	t_buf *tmp;

	i = 0;
	tmp = NULL;
	if (!buffer)
		fatal("error in (list_len)");
	tmp = buffer;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

