/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_term.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 15:43:22 by mda-cost          #+#    #+#             */
/*   Updated: 2016/06/08 15:43:23 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"
#include "../include/parser.h"

void	ft_set_term(void)
{
	struct termios	tios;

	tcgetattr(0, &tios);
	tios.c_lflag &= ~(ICANON);
	tios.c_lflag &= ~(ECHO);
	if (tcsetattr(0, TCSADRAIN, &tios) == -1)
		ft_error("tcsetattr: fail");
}

void	ft_restore_term(void)
{
	struct termios	tios;

	tcgetattr(0, &tios);
	tios.c_lflag |= (ICANON | ECHO | ISIG);
	tcsetattr(0, TCSADRAIN, &tios);
}
