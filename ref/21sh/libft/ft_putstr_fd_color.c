/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 15:41:21 by mda-cost          #+#    #+#             */
/*   Updated: 2016/04/08 15:41:26 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd_color(char const *s, int fd, char *color)
{
	ft_putstr(color);
	write(fd, s, ft_strlen(s));
	ft_putstr("\033[0m");
}
