/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmd_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/12/25 07:29:01 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh.h"

/*
** gets the fd of a file through its name
*/

int get_fd(char *file)
{
	int fd;
	mode_t mode;

	fd = 0;
	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	if (!file)
		fatal("Error: (get_fd)");
	if ((fd = open(file, O_CREAT | O_RDWR | O_TRUNC, mode)) < 0)
		fatal("Could not open in (get_fd)");
	return (fd);
}

t_fds *ft_new_fd(char *file_name)
{
	int new_fd;
	t_fds *new;

	new = NULL;
	new_fd = 0;
	if (!file_name)
		fatal("Error (ft_new_in_fd)");
	if (!(new = (t_fds *) malloc(sizeof(t_fds) * 1)))
		fatal("Malloc error: (ft_new_in_fd)");
	new->fd = get_fd(file_name);
	new->next = NULL;
	return (new);
}


void add_fd(t_fds **begin_list, char *file_name)
{
	t_fds *tmp;

	tmp = NULL;
	if (!(*begin_list))
	{
		(*begin_list) = ft_new_fd(file_name);
		return;
	}
	tmp = (*begin_list);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_new_fd(file_name);
}
