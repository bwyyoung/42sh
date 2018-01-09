/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 15:56:55 by mda-cost          #+#    #+#             */
/*   Updated: 2016/11/03 21:03:36 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

static void	ft_format(t_shell *sh)
{
	chk_trim(sh);
	chk_rm_endchar(sh->line, '\n');
	chk_rm_endchar(sh->line, ';');
	chk_spaces(sh->line);
}

static void	ft_syntax_error(int error)
{
	ft_putstr_fd("syntax error near unexpected token ", 2);
	if (error == 1)
		ft_putendl_fd("`;'", 2);
	else if (error == 2)
		ft_putendl_fd("`>'", 2);
	else if (error == 3)
		ft_putendl_fd("`|'", 2);
	else if (error == 4)
		ft_putendl_fd("`<'", 2);
	else if (error == 5)
		ft_putendl_fd("`[' or `]'", 2);
	else if (error == 6)
		ft_putendl_fd("parenthesis", 2);
	else if (error == 7)
		ft_putendl_fd("backquotes", 2);
}

int			chk_nextchar(char *str, char c)
{
	int i;

	i = 0;
	while (i < ft_strlen(str) && str[i])
	{
		if (str[i] == ' ')
			i++;
		else if (str[i] == c)
			return (1);
		else
			return (0);
	}
	return (0);
}

static int	chk_forbidden(char *s)
{
	int		i;
	int		jump;

	i = 0;
	jump = 0;
	while (i < ft_strlen(s) && s[i])
	{
		if ((jump = ft_char_to_jump(s[i])) > 0 && ft_antislashed(s, i) == 0)
			ft_jump(s, &i, jump);
		else
		{
			if (s[i] == '\0')
				return (0);
			if ((s[i] == '[' || s[i] == ']') && ft_antislashed(s, i) == 0)
				return (5);
			if ((s[i] == '(' || s[i] == ')') && ft_antislashed(s, i) == 0)
				return (6);
			if (s[i] == '`' && ft_antislashed(s, i) == 0)
				return (7);
		}
		i++;
	}
	return (0);
}

int			ft_syntax(t_shell *sh)
{
	int		ret;

	ret = 0;
	ft_format(sh);
	ret = chk_operators(sh->line);
	if (ret > 0)
	{
		ft_syntax_error(ret);
		return (ret);
	}
	ret = chk_forbidden(sh->line);
	if (ret > 0)
		ft_syntax_error(ret);
	return (ret);
}
