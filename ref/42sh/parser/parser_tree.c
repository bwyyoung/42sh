/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 11:50:10 by mda-cost          #+#    #+#             */
/*   Updated: 2016/04/05 11:50:12 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

static t_node	*ft_create_node(void)
{
	t_node	*node;

	node = NULL;
	if (!(node = (t_node*)malloc(sizeof(t_node))))
		return (NULL);
	ft_bzero(node, sizeof(t_node));
	node->stdin = 0;
	node->stdout = 1;
	node->stderr = 2;
	node->fd_from = -2;
	node->fd_to = -2;
	node->cmd = NULL;
	return (node);
}

static char		**ft_splitter(char *command, int *data, char **ope)
{
	int		i;
	char	**array;

	i = 0;
	array = NULL;
	if (!(array = (char **)malloc(sizeof(char *) * 4)))
		ft_error("splitter: malloc fail");
	ft_bzero(array, sizeof(char *) * 4);
	array[0] = ft_strndup(command, data[POSITION]);
	array[1] = ft_strndup(&command[data[POSITION]],
				ft_strlen(ope[data[OPERATOR]]));
	array[2] = ft_strdup(&command[data[POSITION] +
				ft_strlen(ope[data[OPERATOR]])]);
	array = ft_arraytrim(array);
	return (array);
}

t_node			*ft_create_ast(char *command, char **ope, t_info *info)
{
	t_node	*node;
	char	**splitted;
	int		data[2];

	splitted = NULL;
	node = ft_create_node();
	ft_bzero(data, sizeof(int) * 2);
	if ((ft_find_operator(command, data)) != 0)
	{
		splitted = ft_splitter(command, data, ope);
		node->type = data[OPERATOR];
		node->elem = ft_strdup(splitted[1]);
		node->left = ft_create_ast(splitted[0], ope, info);
		if (ft_strcmp(splitted[1], "<<") == 0)
			ft_heredoc(splitted);
		node->right = ft_create_ast(splitted[2], ope, info);
		ft_arrayfree(splitted);
	}
	else
	{
		node->elem = ft_strdup(command);
		ft_variable(node, info->e->env);
		ft_extract(node);
	}
	return (node);
}
