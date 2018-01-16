/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/12/25 07:29:01 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh.h"

// TESTING
void print_list_test(t_buf *buffer)
{
	t_buf *tmp;

	tmp = buffer;

	ft_putendl("\n\n\n--> ");
	while (tmp)
	{
		ft_putstr(tmp->key);
		tmp = tmp->next;
	}
	ft_putendl(" <--\n\n\n");

}

