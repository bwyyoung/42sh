/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 19:09:02 by mda-cost          #+#    #+#             */
/*   Updated: 2014/11/11 20:46:56 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str_new;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	str_new = ft_strnew(len);
	if (!str_new)
		return (NULL);
	while (i < len && s[i])
	{
		str_new[i] = s[start];
		i++;
		start++;
	}
	return (str_new);
}
