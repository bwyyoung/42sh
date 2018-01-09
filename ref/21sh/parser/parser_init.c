/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 11:52:21 by mda-cost          #+#    #+#             */
/*   Updated: 2016/11/03 21:02:33 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/termcaps.h"
#include "../include/parser.h"

void		ft_browser_func(t_info *info)
{
	info->tab_browser[0] = br_semicol;
	info->tab_browser[COMMA] = br_semicol;
	info->tab_browser[REDIR_L] = br_redirections;
	info->tab_browser[HEREDOC] = br_redirections;
	info->tab_browser[PIPE] = br_pipe;
	info->tab_browser[REDIR_R] = br_redirections;
	info->tab_browser[APPEND] = br_redirections;
	info->tab_browser[F_REDIR_L] = br_redirections;
	info->tab_browser[F_REDIR_R] = br_redirections;
	info->tab_browser[9] = NULL;
}

char		**ft_fill_operators(void)
{
	char	**sep;

	sep = NULL;
	if (!(sep = (char **)malloc(sizeof(char *) * 10)))
		ft_error("fill_operator: malloc fail");
	ft_bzero(sep, sizeof(sep));
	sep[0] = ft_strdup("NOTHING");
	sep[COMMA] = ft_strdup(";");
	sep[PIPE] = ft_strdup("|");
	sep[HEREDOC] = ft_strdup("<<");
	sep[APPEND] = ft_strdup(">>");
	sep[F_REDIR_L] = ft_strdup("<&");
	sep[F_REDIR_R] = ft_strdup(">&");
	sep[REDIR_L] = ft_strdup("<");
	sep[REDIR_R] = ft_strdup(">");
	sep[9] = NULL;
	return (sep);
}
