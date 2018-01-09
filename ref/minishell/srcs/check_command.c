/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/17 21:29:23 by mda-cost          #+#    #+#             */
/*   Updated: 2015/04/20 16:45:22 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char		*ft_build_path_cmd(char *path, char *cmd)
{
	char	*full_path;
	char	*add_slash;

	full_path = NULL;
	add_slash = NULL;
	add_slash = ft_strjoin("/", cmd);
	full_path = ft_strjoin(path, add_slash);
	ft_freestr(add_slash);
	return (full_path);
}

void		ft_check_access(char **cmd, t_env *e)
{
	int		i;
	int		acc;
	char	*full_path;

	i = 0;
	acc = -1;
	while (e->paths[i])
	{
		full_path = NULL;
		full_path = ft_build_path_cmd(e->paths[i], cmd[0]);
		if ((acc = access(full_path, X_OK)) == 0)
		{
			ft_fork_exec(full_path, cmd, e);
			ft_freestr(full_path);
			break ;
		}
		else
			ft_freestr(full_path);
		i++;
	}
	if (acc == -1)
	{
		ft_putstr_fd("ft_minishell2: command not found: ", 2);
		ft_putendl_fd(cmd[0], 2);
	}
}

void		ft_check_cmd(char **cmd, t_env *e)
{
	ft_check_access(cmd, e);
}
