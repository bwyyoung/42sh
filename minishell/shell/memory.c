/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 18:55:08 by mda-cost          #+#    #+#             */
/*   Updated: 2016/06/01 15:57:29 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"
#include "../include/termcaps.h"
#include "../include/parser.h"

void	ft_free_list(t_hist *list)
{
	t_hist *tmp;

	if (list == 0)
		return ;
	while (list->prev != 0)
		list = list->prev;
	while (list != 0)
	{
		tmp = list->next;
		free(list->cmd);
		free(list);
		list = tmp;
	}
	list = 0;
}

void	ft_free_sh(t_shell *sh)
{
	if (sh)
	{
		if (sh->line)
			free(sh->line);
		if (sh->prompt)
			free(sh->prompt);
		if (sh->copybuff)
			free(sh->copybuff);
		if (sh->caps)
			free(sh->caps);
		if (sh->history)
			ft_free_list(sh->history);
		free(sh);
	}
}

void	ft_free_env(t_env *e)
{
	if (e->env != NULL && ft_tablen(e->env) > 0)
		ft_arrayfree(e->env);
	if (e->cmd != NULL && ft_tablen(e->cmd) > 0)
		ft_arrayfree(e->cmd);
	if (e->paths != NULL && ft_tablen(e->paths) > 0)
		ft_arrayfree(e->paths);
	if (e->final_path != NULL && ft_strlen(e->final_path) > 0)
		free(e->final_path);
	free(e);
}

void	ft_free_info(t_info *info)
{
	if (info)
		free(info);
}

void	ft_quit(t_info *info)
{
	ft_free_sh(info->sh);
	ft_free_env(info->e);
	ft_free_info(info);
	ft_restore_term();
	ft_putendl("exit");
}
