/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 15:07:23 by mda-cost          #+#    #+#             */
/*   Updated: 2016/11/03 21:01:49 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

char	*ft_delpar(char *cmd)
{
	int		i;
	int		y;
	char	*s;

	i = 0;
	y = 0;
	s = cmd;
	while (s && (s[i] != '\0'))
	{
		if (s[i] == '(')
		{
			tc_delchar(s, i);
			while (s[i] != ')')
				tc_delchar(s, i);
			tc_delchar(s, i);
		}
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_delquotes(char *cmd)
{
	int		i;
	int		y;
	char	*s;

	i = 0;
	y = 0;
	s = cmd;
	while (s && (s[i] != '\0'))
	{
		if (s[i] == '"')
		{
			tc_delchar(s, i);
			while (s[i] != '"')
				tc_delchar(s, i);
			tc_delchar(s, i);
		}
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_delbracks(char *cmd)
{
	int		i;
	int		y;
	char	*s;

	i = 0;
	y = 0;
	s = cmd;
	while (s && (s[i] != '\0'))
	{
		if (s[i] == '[')
		{
			tc_delchar(s, i);
			while (s[i] != ']')
				tc_delchar(s, i);
			tc_delchar(s, i);
		}
		i++;
	}
	s[i] = '\0';
	return (s);
}
