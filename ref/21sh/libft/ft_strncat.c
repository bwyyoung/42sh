/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:06:49 by mda-cost          #+#    #+#             */
/*   Updated: 2014/11/04 16:51:20 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *dst, char *src, size_t n)
{
	size_t		i;
	size_t		size_dst;

	i = 0;
	size_dst = 0;
	while (dst[size_dst])
		size_dst++;
	while (i < n && src[i])
	{
		dst[size_dst] = src[i];
		size_dst++;
		i++;
	}
	dst[size_dst] = '\0';
	return (dst);
}
