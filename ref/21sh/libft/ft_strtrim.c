/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 20:50:14 by mda-cost          #+#    #+#             */
/*   Updated: 2014/11/17 19:08:27 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strtrim(char const *s)
{
	char	*res;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (!s)
		return (NULL);
	if (!(res = ft_strnew(ft_strlen(s) + 1)))
		return (NULL);
	while (s[i])
	{
		if (!(s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
			k++;
		if (k)
			res[j++] = s[i];
		i++;
	}
	while (j > 0 && (res[j - 1] == ' ' ||
		res[j - 1] == '\n' || res[j - 1] == '\t'))
		j--;
	res[j] = '\0';
	return (res);
}
