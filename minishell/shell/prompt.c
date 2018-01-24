/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/16 16:57:49 by mda-cost          #+#    #+#             */
/*   Updated: 2016/06/01 15:59:16 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

static char	*ft_create_prompt(char *path)
{
	char	**array;
	char	*dir;
	char	*prompt;

	array = NULL;
	dir = NULL;
	prompt = NULL;
	if (path && ft_strlen(path) == 1 && ft_strcmp(path, "/") == 0)
		dir = ft_strdup("/");
	else if (ft_strlen(path) > 1)
	{
		array = ft_strsplit(path, '/');
		if (array && ft_tablen(array) > 0)
			dir = ft_strdup(array[ft_tablen(array) - 1]);
	}
	else
		dir = ft_strdup("dir");
	prompt = ft_strjoin(dir, " > ");
	ft_arrayfree(array);
	ft_freestr(dir);
	return (prompt);
}

static void	ft_prompt(t_shell *sh)
{
	char	*path;

	path = getcwd(NULL, 1024);
	if (path)
	{
		sh->prompt = ft_create_prompt(path);
		sh->prompt_len = ft_strlen(sh->prompt);
		ft_freestr(path);
	}
	else
	{
		sh->prompt = ft_strdup(" > ");
		sh->prompt_len = ft_strlen(sh->prompt);
	}
}

void		ft_reset_prompt(t_shell *sh)
{
	if (ft_strlen(sh->prompt) > 0)
	{
		ft_bzero(sh->prompt, ft_strlen(sh->prompt));
		ft_freestr(sh->prompt);
		sh->prompt = NULL;
	}
	ft_prompt(sh);
}
