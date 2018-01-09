/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_init_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 16:46:36 by mda-cost          #+#    #+#             */
/*   Updated: 2016/06/01 16:46:37 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"
#include "../include/parser.h"
#include "../include/termcaps.h"

static t_hist	*ft_create_elem(char *line)
{
	t_hist	*new_elem;

	new_elem = NULL;
	if (!(new_elem = (t_hist *)malloc(sizeof(t_hist))))
		return (NULL);
	new_elem->cmd = ft_strnew(LINE_SIZE);
	if (line != NULL)
		ft_strcpy(new_elem->cmd, line);
	new_elem->next = NULL;
	new_elem->prev = NULL;
	return (new_elem);
}

t_hist			*ft_add_head_double(t_hist *head, char *line)
{
	t_hist	*new;

	new = NULL;
	new = ft_create_elem(line);
	if (head != NULL)
	{
		new->next = head;
		head->prev = new;
	}
	return (new);
}

int				ft_valid_term(t_info *info)
{
	char	*term_buffer;
	char	*term;
	int		is_tgetent;

	is_tgetent = 0;
	if ((term = ft_return_rep("TERM=", info->e->env, 5)) != NULL)
	{
		if (ft_strcmp(term, "xterm-256color") != 0)
			return (0);
		if ((term_buffer = (char *)malloc(sizeof(char) * TERM_SIZE)))
		{
			is_tgetent = tgetent(term_buffer, term);
			free(term_buffer);
		}
	}
	return (is_tgetent);
}
