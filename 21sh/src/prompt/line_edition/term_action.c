/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/12/25 07:29:01 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_sh.h"

/*
** determines if the inputted buffer
** represents an action
*/

T_BOOL term_action(char *buf)
{
	if (!buf)
		return (FALSE);
	if (ft_strcmp(buf, K_RETURN) == 0)
		return (TRUE);
	if (ft_strcmp(buf, K_LEFT) == 0)
		return (TRUE);
	if (ft_strcmp(buf, K_RIGHT) == 0)
		return (TRUE);
	if (ft_strcmp(buf, K_UP) == 0)
		return (TRUE);
	if (ft_strcmp(buf, K_DOWN) == 0)
		return (TRUE);
	if (ft_strcmp(buf, K_BACKSPACE) == 0)
		return (TRUE);
	return (FALSE);
}