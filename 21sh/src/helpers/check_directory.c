/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_directory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/12/25 07:29:01 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh.h"

/*
** receives a directory path
** and checks the directory for
** sought after filename
*/

T_BOOL check_directory(char *dir_path, char *file)
{
	DIR *dir;
	struct dirent *ent;
	//char *bin;

	dir = NULL;
	ent = NULL;
	//printf("check_directory %s\n", dir_path);
	if (!(dir = opendir(dir_path)))
		return (FALSE);
	if (!dir_path || !file)
		fatal("Error in (check_directory)"); // remove later
	while ((ent = readdir(dir)))
	{
		// iterate over all binaries in folder to look for sought after binary
		if (ft_strcmp(ent->d_name, file) == 0)
		{
			closedir(dir);
			return (TRUE);
		}
	}
	closedir(dir);
	return (FALSE);
}
