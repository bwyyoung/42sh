/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/16 16:58:34 by mda-cost          #+#    #+#             */
/*   Updated: 2015/04/20 16:45:44 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void		ft_fork_exec(char *path, char **cmd, t_env *e)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(path, cmd, e->env) == -1)
			ft_error("ft_cmd_start: execve failed");
	}
	else
		wait(0);
}
