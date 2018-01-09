/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 12:58:23 by mda-cost          #+#    #+#             */
/*   Updated: 2014/11/10 15:22:33 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*elem;

	elem = (t_list*)malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	if (!content)
	{
		elem->content = NULL;
		elem->content_size = 0;
		elem->next = NULL;
	}
	else
	{
		elem->content = malloc(content_size);
		elem->content_size = content_size;
		if (elem->content)
			ft_memcpy(elem->content, content, content_size);
		elem->next = NULL;
	}
	return (elem);
}
