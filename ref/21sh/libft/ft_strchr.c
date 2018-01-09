/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:24:42 by mda-cost          #+#    #+#             */
/*   Updated: 2014/11/05 20:57:40 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	cc;
	int		i;

	cc = (char)c;
	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != cc)
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)(&str[i]));
}
