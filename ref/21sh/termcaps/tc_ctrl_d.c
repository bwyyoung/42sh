/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_ctrl_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 21:32:40 by mda-cost          #+#    #+#             */
/*   Updated: 2016/06/01 16:35:50 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

int			ft_ctrl_d(char *line, t_shell *sh)
{
	char	key[8];

	ft_bzero(key, 8);
	key[0] = '\0';
	if (ft_strlen(line) <= 401)
		tc_insert_char(line, key, sh);
	return (1);
}
