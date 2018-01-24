/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:47:27 by mda-cost          #+#    #+#             */
/*   Updated: 2014/11/11 18:14:01 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*str;

	if (!size)
		return (NULL);
	str = (char *)malloc(sizeof(str) * size);
	if (!str)
		return (NULL);
	ft_memset(str, 0, size);
	return ((void *)str);
}
