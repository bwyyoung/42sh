/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinquotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeletan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 06:30:27 by adeletan          #+#    #+#             */
/*   Updated: 2017/04/08 05:19:07 by adeletan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isinquotes(char const *cmd, int pos)
{
	int index;
	int type;

	index = 0;
	type = 0;
	while (index < pos)
	{
		if (ft_isquotes(cmd[index]) && cmd[index - 1] != '\\')
		{
			if (cmd[index] == '\"')
				type = 1;
			else if (cmd[index] == '`')
				type = 2;
			else
				type = 3;
			index = ft_endquo(cmd, index);
			if (index > pos)
				return (type);
		}
		++index;
	}
	return (0);
}
