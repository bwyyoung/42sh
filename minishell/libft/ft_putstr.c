/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:05:37 by mda-cost          #+#    #+#             */
/*   Updated: 2014/11/07 20:49:02 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *str)
{
	unsigned int		i;

	i = 0;
	if (str == NULL)
		write(1, "(null)", 6);
	else
	{
		while (str[i])
		{
			ft_putchar(str[i]);
			i++;
		}
	}
}
