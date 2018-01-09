/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 11:49:30 by mda-cost          #+#    #+#             */
/*   Updated: 2016/11/03 21:02:48 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

static int	ft_is_keyword(char c)
{
	if (c == '<' || c == '>' || c == '&' || c == '|'
		|| c == '{' || c == '}' || c == '[' || c == ']'
		|| c == '(' || c == ')' || c == '"' || c == '\''
		|| c == ';' || c == ' ')
	{
		return (0);
	}
	return (1);
}

static char	*ft_heredoc_end(char **splitted)
{
	int		i;
	char	*keyword;
	char	*tmp;

	i = 0;
	tmp = splitted[2];
	keyword = ft_strnew(LINE_SIZE);
	while (tmp[i] && ft_is_keyword(tmp[i]))
	{
		keyword[i] = tmp[i];
		i++;
	}
	keyword[i] = '\0';
	if (ft_strlen(&tmp[i]) > 0)
		splitted[2] = ft_strjoin("/tmp/.chevron ", &tmp[i]);
	else
		splitted[2] = ft_strdup("/tmp/.chevron");
	ft_freestr(tmp);
	return (keyword);
}

void		ft_heredoc(char **splitted)
{
	int		fd;
	t_shell	*sh;
	char	*end;
	char	*tmp;

	tmp = NULL;
	sh = ft_shell_malloc();
	end = ft_heredoc_end(splitted);
	if ((fd = open("/tmp/.chevron", O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR |
		S_IRGRP | S_IWGRP | S_IWUSR)) == -1)
		ft_error("error. heredoc not valid. abort");
	while (ft_termcaps_get_line(sh->line, sh) > 0)
	{
		if ((tmp = ft_strchr(sh->line, '\n')) != NULL)
			*tmp = '\0';
		if (ft_strcmp(end, sh->line) == 0)
			break ;
		ft_putendl_fd(sh->line, fd);
		ft_bzero(sh->line, ft_strlen(sh->line));
	}
	ft_freestr(end);
	close(fd);
	ft_free_sh(sh);
}
