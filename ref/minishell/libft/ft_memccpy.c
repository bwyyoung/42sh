/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:47:41 by mda-cost          #+#    #+#             */
/*   Updated: 2014/11/05 16:43:54 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*p_dst;
	const char		*p_src;
	size_t			i;

	i = 0;
	p_dst = (char *)dst;
	p_src = (const char *)src;
	while (i < n)
	{
		p_dst[i] = p_src[i];
		if (p_src[i] == c)
			return ((char *)(dst + i + 1));
		i++;
	}
	return (NULL);
}
