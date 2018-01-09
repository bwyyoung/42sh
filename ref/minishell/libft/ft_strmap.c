/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:52:16 by mda-cost          #+#    #+#             */
/*   Updated: 2014/11/11 20:43:24 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str_new;
	int		i;

	if (!s || !f)
		return (NULL);
	i = 0;
	str_new = ft_strnew(ft_strlen(s));
	while (s[i])
	{
		str_new[i] = f(s[i]);
		i++;
	}
	return (str_new);
}
