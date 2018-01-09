/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 20:08:07 by mda-cost          #+#    #+#             */
/*   Updated: 2014/11/10 15:23:30 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	size_t	j;
	size_t	y;

	i = 0;
	while (dst[i] != '\0')
		i++;
	len = i + ft_strlen(src);
	j = size - i - 1;
	if (i < size)
	{
		y = 0;
		while (src[y] && y < j)
		{
			dst[i] = src[y];
			i++;
			y++;
		}
		dst[i] = '\0';
	}
	if (size < i)
		return (len - i + size);
	return (len);
}
