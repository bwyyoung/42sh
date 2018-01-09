/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_extract.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 21:02:09 by mda-cost          #+#    #+#             */
/*   Updated: 2016/11/03 21:02:11 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"
#include <stdio.h>

void			ft_update_fd(t_node *node)
{
	if (node->fd_from != -2 && node->fd_to != -2)
	{
		if (node->fd_to != -1)
			dup2(node->fd_to, node->fd_from);
		else
			close(node->fd_from);
		node->fd_from = -2;
		node->fd_to = -2;
	}
}

static void		ft_extract_fd(t_node *node, char *s)
{
	int		i;

	i = 0;
	while (s[i] != '&' && i < (ft_strlen(s) - 1))
		i++;
	if (i == 1)
		node->fd_from = 1;
	else
		node->fd_from = ft_atoi(s);
	if (ft_isdigit(s[i + 1]) == 1)
		node->fd_to = ft_atoi(&s[i + 1]);
	else if (s[i + 1] == '-')
		node->fd_to = -1;
}

static char		**ft_arraypurify(char **array)
{
	int		i;
	int		y;
	char	**n_arr;

	i = 0;
	y = 0;
	n_arr = (char **)malloc(sizeof(char *) * (ft_tablen(array) + 1));
	if (!n_arr)
		return (NULL);
	ft_bzero((void *)n_arr, sizeof(char *) * (ft_tablen(array) + 1));
	while (array[i] != NULL)
	{
		if (ft_strstr(array[i], ">&") == NULL
				|| array[i][0] == '"' || array[i][0] == '\'')
			n_arr[y++] = ft_strdup(array[i]);
		i++;
	}
	ft_arrayfree(array);
	return (n_arr);
}

static void		ft_find_fd(t_node *node)
{
	int		i;

	i = 0;
	while (node->cmd[i] != NULL)
	{
		if (node->cmd[i][0] != '"' && node->cmd[i][0] != '\'')
		{
			if (ft_strstr(node->cmd[i], ">&"))
			{
				ft_extract_fd(node, node->cmd[i]);
				node->cmd = ft_arraypurify(node->cmd);
			}
		}
		i++;
	}
}

void			ft_extract(t_node *node)
{
	node->cmd = ft_jumpsplit(node->elem, ' ');
	node->cmd = ft_arraytrim(node->cmd);
	ft_find_fd(node);
	while (ft_trimquotes(node->cmd) == 1)
		;
	if (ft_tablen(node->cmd) >= 1 && ft_strcmp(node->cmd[0], "echo") != 0)
		ft_cleanslash(node->cmd);
}
