/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayfree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/16 17:50:22 by mda-cost          #+#    #+#             */
/*   Updated: 2015/04/16 17:54:08 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arrayfree(char **array)
{
	int		i;
	int		size;

	size = ft_tablen(array);
	i = 0;
	if (array != NULL)
	{
		while (i < size)
		{
			ft_freestr(array[i]);
			i++;
		}
		free(array);
	}
}
