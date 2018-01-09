/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:09:09 by mda-cost          #+#    #+#             */
/*   Updated: 2014/11/08 16:08:46 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (s2[0] == '\0' || s2 == NULL)
		return ((char *)s1);
	while (s1[i])
	{
		if (s1[i] == s2[y])
			y++;
		else
			y = 0;
		if (!s2[y])
			return ((char *)s1 + (i - (y - 1)));
		i++;
	}
	return (NULL);
}
