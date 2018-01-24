/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_jump.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:27:08 by mda-cost          #+#    #+#             */
/*   Updated: 2016/11/07 19:27:09 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

char	ft_char_to_jump(char c)
{
	int		ret;

	ret = 0;
	if (c == '"')
		ret = '"';
	else if (c == '\'')
		ret = '\'';
	return (ret);
}

void	ft_jump(char *s, int *i, char jump)
{
	*i = *i + 1;
	while (*i < ft_strlen(s))
	{
		if (s[*i] == jump && ft_antislashed(s, *i) == 0)
			return ;
		*i = *i + 1;
	}
}
