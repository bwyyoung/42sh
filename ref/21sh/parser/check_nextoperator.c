/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nextoperator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:25:17 by mda-cost          #+#    #+#             */
/*   Updated: 2016/11/07 19:25:18 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

int		chk_nextoperator(char *line)
{
	if (chk_nextchar(line, ';'))
		return (1);
	if (chk_nextchar(line, '<'))
		return (1);
	if (chk_nextchar(line, '>'))
		return (1);
	if (chk_nextchar(line, '|'))
		return (1);
	return (0);
}

int		chk_checking(char *line, int len, int i, char c)
{
	if (i == 0 && line[i] == c)
		return (0);
	if (i < len - 2 && line[i] == c &&
			line[i + 1] == c && line[i + 2] == c)
	{
		return (0);
	}
	if (i < len - 2 &&
			i != 0 && line[i] == c && chk_nextoperator(&line[i + 2]))
		return (0);
	if (line[len - 1] == c)
		return (0);
	return (1);
}
