/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 13:54:05 by mda-cost          #+#    #+#             */
/*   Updated: 2014/11/12 16:25:19 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *newelem;
	t_list *begin_list;

	tmp = lst;
	if (!lst || !f)
		return (NULL);
	newelem = ft_lstnew(f(tmp->content), tmp->content_size);
	begin_list = newelem;
	while (tmp)
	{
		tmp = tmp->next;
		newelem = newelem->next;
		newelem = ft_lstnew(f(tmp->content), tmp->content_size);
	}
	return (begin_list);
}
