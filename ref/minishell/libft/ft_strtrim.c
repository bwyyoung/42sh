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

static int			strisblank(char c)
{
	if (c != ' ' && c != '\n' && c != '\t')
		return (0);
	return (1);
}

static char			*fillstrnew(int i, int j, char const *s, char *strnew)
{
	int	k;

	k = 0;
	while (i <= j)
	{
		strnew[k] = s[i];
		k++;
		i++;
	}
	strnew[k] = '\0';
	return (strnew);
}

char				*ft_strtrim(char const *s)
{
	int					i;
	unsigned int		j;
	char				*strnew;

	strnew = NULL;
	if (s)
	{
		j = ft_strlen(s) - 1;
		i = 0;
		while (strisblank(s[i]))
			i++;
		strnew = (char *)malloc(sizeof(char) * (j - i + 1));
		while (strisblank(s[j]))
			j--;
		if (i == 0 && j == ft_strlen(s) - 1)
			return (ft_strdup(s));
		return (fillstrnew(i, j, s, strnew));
	}
	return (NULL);
}
