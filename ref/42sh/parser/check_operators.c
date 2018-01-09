/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operators.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 17:59:49 by mda-cost          #+#    #+#             */
/*   Updated: 2016/11/03 21:03:31 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

static int		chk_semicol(char *line)
{
	int		i;
	char	jump;

	i = 0;
	while (line[i])
	{
		if ((jump = ft_char_to_jump(line[i])) > 0
											&& ft_antislashed(line, i) == 0)
			ft_jump(line, &i, jump);
		else
		{
			if (i == 0 && line[i] == ';')
				return (0);
			if (i != 0 && line[i] == ';' && chk_nextoperator(&line[i + 1]))
				return (0);
			if (line[ft_strlen(line) - 1] == ';')
				return (0);
		}
		i++;
	}
	return (1);
}

static int		chk_right(char *line)
{
	int		i;
	int		len;
	char	jump;

	i = 0;
	len = ft_strlen(line);
	while (line[i])
	{
		if ((jump = ft_char_to_jump(line[i])) > 0
											&& ft_antislashed(line, i) == 0)
			ft_jump(line, &i, jump);
		else
		{
			if (chk_checking(line, len, i, '>') == 0)
				return (0);
		}
		i++;
	}
	return (1);
}

static int		chk_pipe(char *line)
{
	int		i;
	int		len;
	char	jump;

	i = 0;
	len = ft_strlen(line);
	while (line[i])
	{
		if ((jump = ft_char_to_jump(line[i])) > 0
											&& ft_antislashed(line, i) == 0)
			ft_jump(line, &i, jump);
		else
		{
			if (i == 0 && line[i] == '|')
				return (0);
			if (line[i] == '|' && chk_nextoperator(&line[i + 1]))
				return (0);
			if (line[len - 1] == '|')
				return (0);
		}
		i++;
	}
	return (1);
}

static int		chk_left(char *line)
{
	int		i;
	int		len;
	char	jump;

	i = 0;
	len = ft_strlen(line);
	while (line[i])
	{
		if ((jump = ft_char_to_jump(line[i])) > 0
											&& ft_antislashed(line, i) == 0)
			ft_jump(line, &i, jump);
		else
		{
			if (chk_checking(line, len, i, '<') == 0)
				return (0);
		}
		i++;
	}
	return (1);
}

int				chk_operators(char *line)
{
	if (!line)
		return (1);
	if (chk_semicol(line) == 0)
		return (1);
	if (chk_right(line) == 0)
		return (2);
	if (chk_pipe(line) == 0)
		return (3);
	if (chk_left(line) == 0)
		return (4);
	return (0);
}
