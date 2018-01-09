/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:15:26 by mda-cost          #+#    #+#             */
/*   Updated: 2014/11/05 17:30:18 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const char		*p_str;
	size_t			i;

	p_str = (const char *)str;
	i = 0;
	while (i < n)
	{
		if (p_str[i] == c)
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
