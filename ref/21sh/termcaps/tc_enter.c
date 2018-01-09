/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_enter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 16:37:32 by mda-cost          #+#    #+#             */
/*   Updated: 2016/06/01 16:37:33 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/termcaps.h"

void	tc_enter(char *line, t_shell *sh, t_caps *caps)
{
	t_caps	*useless;

	if (sh->select == 1)
		tc_unselect(line, sh, ft_strlen(line) - 1);
	line[ft_strlen(line)] = '\n';
	write(1, "\n", 1);
	useless = caps;
}
