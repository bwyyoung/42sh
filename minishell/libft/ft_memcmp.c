/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:33:59 by mda-cost          #+#    #+#             */
/*   Updated: 2014/11/05 18:13:20 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p_s1;
	unsigned char	*p_s2;
	size_t			i;

	p_s1 = (unsigned char *)s1;
	p_s2 = (unsigned char *)s2;
	i = 0;
	if ((!s1 && !s2) || (p_s1[0] == '\0' && p_s2[0] == '\0'))
		return (0);
	while ((p_s1[i] == p_s2[i]) && (i < n))
		i++;
	if (i == n)
		i = i - 1;
	return ((int)(p_s1[i] - p_s2[i]));
}
