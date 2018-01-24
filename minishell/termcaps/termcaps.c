/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 16:08:45 by mda-cost          #+#    #+#             */
/*   Updated: 2016/06/01 16:43:10 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"
#include "../include/parser.h"

static void	ft_reset_line(t_shell *sh)
{
	char	*s;

	s = NULL;
	s = ft_strnew(LINE_SIZE);
	if (sh->line != NULL)
		ft_freestr(sh->line);
	sh->line = NULL;
	sh->line = s;
}

static void	ft_shell_reset(t_shell *sh)
{
	if (sh)
	{
		ft_reset_line(sh);
		sh->x = 0;
		sh->y = 0;
		sh->s_x = 0;
		sh->s_y = 0;
		sh->select = 0;
		ioctl(0, TIOCGWINSZ, &sh->ws);
		if (sh->history)
			ft_free_list(sh->history);
		sh->history = NULL;
		sh->history = ft_load_history();
		sh->exec = 0;
	}
}

static void	ft_semicol(char **array, t_info *info)
{
	t_node	*tree;
	char	**ope;
	int		i;

	i = 0;
	tree = NULL;
	ope = ft_fill_operators();
	if (array)
	{
		while (array[i] && info->sh->exit == 0)
		{
			tree = ft_create_ast(array[i], ope, info);
			ft_restore_term();
			ft_browse_start(tree, info);
			ft_free_tree(tree);
			ft_set_term();
			i++;
		}
	}
	ft_arrayfree(ope);
}

void		ft_parser(t_shell *sh, t_info *info)
{
	char		**array;

	array = NULL;
	info->sh->exec = 1;
	if (sh->line != NULL)
	{
		array = ft_jumpsplit(sh->line, ';');
		array = ft_arraytrim(array);
		ft_semicol(array, info);
		ft_arrayfree(array);
	}
}

int			ft_loop(t_info *info)
{
	t_shell		*sh;

	sh = ft_shell_malloc();
	info->sh = sh;
	while (sh->exit == 0)
	{
		ft_global(info);
		ft_shell_reset(sh);
		ft_reset_prompt(sh);
		ft_termcaps_get_line(sh->line, sh);
		if (ft_strlen(sh->line) == 0)
			return (sh->exit_value);
		ft_add_history(sh->line);
		if (ft_syntax(sh) == 0)
			ft_parser(sh, info);
	}
	return (sh->exit_value);
}
