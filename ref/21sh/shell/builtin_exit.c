/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 19:26:41 by mda-cost          #+#    #+#             */
/*   Updated: 2016/11/03 19:26:45 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

void	builtin_exit(t_info *info)
{
	int		ret;
	int		len;

	ret = 0;
	len = ft_tablen(info->e->cmd);
	if (len > 1)
	{
		info->sh->exit_value = ft_atoi(info->e->cmd[1]);
		if (len > 2)
			ft_putendl_fd("exit: only one numeric argument required", 2);
	}
	info->sh->exit = 1;
}
