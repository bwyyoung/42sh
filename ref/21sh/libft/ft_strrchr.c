/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 20:42:42 by mda-cost          #+#    #+#             */
/*   Updated: 2014/11/11 20:50:45 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	cc;
	int		i;

	cc = (char)c;
	i = 0;
	while (str[i])
		i++;
	while (str[i] != cc && i >= 0)
	{
		i--;
	}
	if (i < 0)
		return (NULL);
	return ((char *)(&str[i]));
}
