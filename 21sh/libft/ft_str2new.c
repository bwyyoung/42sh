/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str2new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 00:28:49 by byoung-w          #+#    #+#             */
/*   Updated: 2017/03/10 00:29:55 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	**ft_str2new(size_t size)
{
	char	**str;
	size_t	i;

	i = 0;
	if (!(str = (char **)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	str[size] = 0;
	while (i < size)
		str[i++] = NULL;
	return (str);
}
