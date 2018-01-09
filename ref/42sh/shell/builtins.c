/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 15:07:22 by mda-cost          #+#    #+#             */
/*   Updated: 2015/04/20 16:45:12 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

int			ft_what_builtin(char **cmd)
{
	if (ft_strcmp(cmd[0], "cd") == 0)
		return (BUILTIN_CD);
	else if (ft_strcmp(cmd[0], "env") == 0)
		return (BUILTIN_ENV);
	else if (ft_strcmp(cmd[0], "setenv") == 0)
		return (BUILTIN_SETENV);
	else if (ft_strcmp(cmd[0], "unsetenv") == 0)
		return (BUILTIN_UNSETENV);
	else if (ft_strcmp(cmd[0], "exit") == 0)
		return (BUILTIN_EXIT);
	else if (ft_strcmp(cmd[0], "echo") == 0)
		return (BUILTIN_ECHO);
	else
		return (0);
}
