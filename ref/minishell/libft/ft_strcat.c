/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:06:31 by mda-cost          #+#    #+#             */
/*   Updated: 2014/11/04 15:42:14 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dst, const char *src)
{
	int		i;
	int		dst_size;

	i = 0;
	dst_size = 0;
	while (dst[dst_size])
		dst_size++;
	while (src[i])
	{
		dst[dst_size] = src[i];
		dst_size++;
		i++;
	}
	dst[dst_size] = '\0';
	return (dst);
}
