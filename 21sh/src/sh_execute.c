/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/12/25 07:29:01 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sh.h"

/*
** function that will either start a process or a builtin
*/

int sh_execute(char **envv, t_shell *shell)
{
	if (!shell->cmds->args || !shell->cmds->args[0])
		return (1);
	if (check_builtins(shell->cmds->args[0]) == TRUE || \
        check_builtin_path(shell) == TRUE)
		return (exec_builtin(shell));
	return (sh_launch(envv, shell));
}