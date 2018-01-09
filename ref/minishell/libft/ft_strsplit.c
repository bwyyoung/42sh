/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 21:01:49 by mda-cost          #+#    #+#             */
/*   Updated: 2015/03/21 21:22:30 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_words(char const *s, char c)
{
	int		i;
	int		a;

	a = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			a++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (a);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		len;
	int		y;

	if (!s)
		return (NULL);
	y = 0;
	i = 0;
	tab = (char**)malloc(sizeof(char*) * ft_nb_words(s, c) + 1);
	if (!tab)
		return (NULL);
	tab[ft_nb_words(s, c)] = NULL;
	while (s[i])
	{
		len = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c && s[i++])
			len++;
		if (s[i - len] && s[i - len] != c)
			tab[y++] = ft_strsub(s, i - len, len);
	}
	return (tab);
}
