/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_delete2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 15:53:08 by mda-cost          #+#    #+#             */
/*   Updated: 2016/11/03 21:01:59 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

char	*ft_delbraces(char *cmd)
{
	int		i;
	int		y;
	char	*s;

	i = 0;
	y = 0;
	s = cmd;
	while (s && (s[i] != '\0'))
	{
		if (s[i] == '{')
		{
			tc_delchar(s, i);
			while (s[i] != '}')
				tc_delchar(s, i);
			tc_delchar(s, i);
		}
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_delbackquotes(char *cmd)
{
	int		i;
	int		y;
	char	*s;

	i = 0;
	y = 0;
	s = cmd;
	while (s && (s[i] != '\0'))
	{
		if (s[i] == '`')
		{
			tc_delchar(s, i);
			while (s[i] != '`')
				tc_delchar(s, i);
			tc_delchar(s, i);
		}
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_delsimplequotes(char *cmd)
{
	int		i;
	int		y;
	char	*s;

	i = 0;
	y = 0;
	s = cmd;
	while (s && (s[i] != '\0'))
	{
		if (s[i] == '\'')
		{
			tc_delchar(s, i);
			while (s[i] != '\'')
				tc_delchar(s, i);
			tc_delchar(s, i);
		}
		i++;
	}
	s[i] = '\0';
	return (s);
}
