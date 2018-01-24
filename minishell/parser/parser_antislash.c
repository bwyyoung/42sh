/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_antislash.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 21:01:40 by mda-cost          #+#    #+#             */
/*   Updated: 2016/11/03 21:03:22 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

int			ft_antislashed(char *s, int i)
{
	int		ret;

	ret = 0;
	if (i > 0)
	{
		if (s[i - 1] == '\\')
			ret = 1;
	}
	return (ret);
}

void		ft_delchar(char *line, char *ptr)
{
	int		i;

	i = 0;
	while (i < ft_strlen(line) && line[i] != *ptr)
		i++;
	if (!line || !(line + 1))
		return ;
	while (line[i + 1] != '\0')
	{
		line[i] = line[i + 1];
		i++;
	}
	line[i] = '\0';
}

void		ft_cleanslash(char **array)
{
	int		i;
	char	*p;

	i = 0;
	p = NULL;
	while (i < ft_tablen(array) && array[i] != NULL)
	{
		while ((p = ft_strstr(array[i], "\\\"")) != NULL ||
				(p = ft_strstr(array[i], "\\\'")) != NULL)
		{
			ft_delchar(array[i], p);
			p = NULL;
		}
		i++;
	}
}

int			ft_trimquotes(char **array)
{
	int		i;
	char	*begin;
	char	*end;

	i = 0;
	begin = NULL;
	end = NULL;
	while (i < ft_tablen(array) && array[i] != NULL)
	{
		begin = array[i];
		end = array[i] + ft_strlen(array[i]) - 1;
		if ((*begin == '"' && *end == '"') || (*begin == '\'' && *end == '\''))
		{
			array[i][ft_strlen(array[i]) - 1] = '\0';
			tc_delchar(array[i], 0);
			return (1);
		}
		i++;
	}
	return (0);
}
