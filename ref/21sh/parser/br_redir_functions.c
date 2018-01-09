/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   br_redir_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:06:17 by mda-cost          #+#    #+#             */
/*   Updated: 2016/11/07 19:06:19 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

static int	open_flag(int type)
{
	int	flag;

	flag = 0;
	if (type == REDIR_R || type == F_REDIR_R)
		flag = O_TRUNC;
	if (type == APPEND)
		flag = O_APPEND;
	if (type == REDIR_L || type == HEREDOC || type == F_REDIR_L)
		flag = O_RDONLY;
	return (flag);
}

void		redir_before_read(t_node *node)
{
	int		fd;

	fd = -1;
	fd = open(node->right->left->cmd[0], O_RDONLY);
	if (fd != -1)
	{
		dup2(fd, node->stdin);
		close(fd);
	}
	else
	{
		ft_putendl_fd("21sh: cannot open file.", 2);
		exit(0);
	}
}

void		redir_before_write(t_node *node)
{
	int		fd;
	int		flag;

	fd = -1;
	flag = open_flag(node->type);
	fd = open(node->right->left->cmd[0], O_WRONLY | flag | O_CREAT,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd != -1)
	{
		dup2(fd, node->stdout);
		ft_update_fd(node->right->left);
		if (node->type == F_REDIR_R)
			dup2(fd, node->stderr);
		close(fd);
	}
	else
	{
		ft_putendl_fd("21sh: cannot open file.", 2);
		exit(0);
	}
}

void		redir_end_read(t_node *node)
{
	int		fd;

	fd = -1;
	fd = open(node->right->cmd[0], O_RDONLY);
	if (fd != -1)
	{
		dup2(fd, node->stdin);
		close(fd);
	}
	else
	{
		ft_putendl_fd("21sh: cannot open file.", 2);
		exit(0);
	}
}

void		redir_end_write(t_node *node)
{
	int		fd;
	int		flag;

	fd = -1;
	flag = open_flag(node->type);
	fd = open(node->right->cmd[0], O_WRONLY | flag | O_CREAT,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd != -1)
	{
		dup2(fd, node->stdout);
		ft_update_fd(node->right);
		if (node->type == F_REDIR_R)
			dup2(fd, node->stderr);
		close(fd);
	}
	else
	{
		ft_putendl_fd("21sh: cannot open file.", 2);
		exit(0);
	}
}
