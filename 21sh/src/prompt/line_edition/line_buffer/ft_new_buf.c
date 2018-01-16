/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_buf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/12/25 07:29:01 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/ft_sh.h"

/*
** allocates a new buffer list element
*/

t_buf *ft_new_buf(char *key)
{
	t_buf *new;

	if (!(new = (t_buf *) malloc(sizeof(t_buf))))
		fatal("Error: could not allocate env var list elem in ft_new_env");
	new->next = NULL;
	new->prev = NULL;
	new->key = NULL;
	new->ind = 0;
	new->key = ft_strdup(key);
	return (new);
}
