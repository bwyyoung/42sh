/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 15:48:33 by mda-cost          #+#    #+#             */
/*   Updated: 2015/05/19 15:48:34 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strndup(char *src, int n)
{
	int		i;
	char	*dst;

	i = 0;
	dst = (char*)malloc(sizeof(char) * (n + 1));
	if (dst == NULL)
		return (NULL);
	ft_bzero((void *)dst, sizeof(char) * (n + 1));
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
