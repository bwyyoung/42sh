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

#include "../include/shell.h"

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

char		*ft_path_builder(char **cmd, t_env *e)
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
		if (check_exec_command(full_path) == 1)
		{
			if ((acc = access(full_path, X_OK)) == 0)
				return (full_path);
		}
		ft_freestr(full_path);
		i++;
	}
	return (NULL);
}

int			check_exec_command(char *path)
{
	struct stat	t_stat;
	char		check;

	if (lstat(path, &t_stat) >= 0)
	{
		check = check_typefile(t_stat.st_mode & S_IFMT);
		if (check == '-' || check == 'l')
			return (1);
		return (0);
	}
	return (0);
}

char		check_typefile(mode_t mode)
{
	if (mode == S_IFREG)
		return ('-');
	if (mode == S_IFDIR)
		return ('d');
	if (mode == S_IFLNK)
		return ('l');
	if (mode == S_IFSOCK)
		return ('s');
	if (mode == S_IFIFO)
		return ('p');
	if (mode == S_IFBLK)
		return ('b');
	if (mode == S_IFCHR)
		return ('c');
	return ('?');
}
