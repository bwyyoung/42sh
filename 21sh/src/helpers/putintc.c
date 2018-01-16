/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putintc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/12/25 07:29:01 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh.h"

/*
** inputs an arbitrary int into
** the stdin
*/

int putintc(int c)
{
	write(STDIN_FILENO, &c, 1);
	return (0);
}
