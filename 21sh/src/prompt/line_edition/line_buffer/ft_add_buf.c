/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_buf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/12/25 07:29:01 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/ft_sh.h"

/*
** iterates to the end of the buf key list
** and then adds the value to it
*/

void ft_add_buf(t_buf **begin_list, char *key)
{
	t_buf *tmp;

	tmp = NULL;
	if (!*begin_list)
	{
		*begin_list = ft_new_buf(key);
		return;
	}
	else
	{
		tmp = *begin_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_new_buf(key);
		tmp->next->prev = tmp;
	}
}