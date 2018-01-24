/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:32:36 by mda-cost          #+#    #+#             */
/*   Updated: 2016/04/25 15:32:39 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putarray(char **array)
{
	int	i;

	i = 0;
	if (array && array[i])
	{
		while (array[i] != NULL)
		{
			ft_putendl(array[i]);
			i++;
		}
	}
}
