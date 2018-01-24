/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 21:02:20 by mda-cost          #+#    #+#             */
/*   Updated: 2016/11/03 21:02:22 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

static int	ft_arraylen(char *s, char c)
{
	int		i;
	int		len;
	char	jump;

	i = 0;
	len = 1;
	jump = 0;
	while (i < ft_strlen(s) && s[i])
	{
		if ((jump = ft_char_to_jump(s[i])) > 0 && ft_antislashed(s, i) == 0)
			ft_jump(s, &i, jump);
		else if (s[i] == c)
			len++;
		i++;
	}
	return (len);
}

static int	ft_seeklen(char *s, char c)
{
	int	i;
	int	jump;

	i = 0;
	jump = 0;
	while (i < ft_strlen(s) && s[i] && s[i] != c)
	{
		if ((jump = ft_char_to_jump(s[i])) > 0 && ft_antislashed(s, i) == 0)
			ft_jump(s, &i, jump);
		i++;
	}
	return (i);
}

char		**ft_jumpsplit(char *s, char c)
{
	char	**array;
	int		i;
	int		len;
	int		y;

	if (!s)
		return (NULL);
	y = 0;
	i = 0;
	len = 0;
	if (!(array = (char **)malloc(sizeof(char *) * (ft_arraylen(s, c) + 1))))
		return (NULL);
	ft_bzero((void *)array, sizeof(char *) * (ft_arraylen(s, c) + 1));
	while (i < ft_strlen(s) && s[i])
	{
		len = ft_seeklen(&s[i], c);
		if (len > 0)
			array[y++] = ft_strndup(&s[i], len);
		i = i + len + 1;
	}
	return (array);
}
