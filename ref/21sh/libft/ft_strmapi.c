/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:07:40 by mda-cost          #+#    #+#             */
/*   Updated: 2014/11/11 20:37:44 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str_new;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	str_new = ft_strnew(ft_strlen(s) + 1);
	if (!str_new)
		return (NULL);
	while (s[i])
	{
		str_new[i] = f(i, s[i]);
		i++;
	}
	return (str_new);
}
