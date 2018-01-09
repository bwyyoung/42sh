/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv_syntax.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:50:06 by mda-cost          #+#    #+#             */
/*   Updated: 2016/11/07 19:50:07 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

static int	is_forbid(char c)
{
	if (c == '<' || c == '>' || c == '&' || c == '|'
		|| c == '{' || c == '}' || c == '[' || c == ']'
		|| c == '(' || c == ')' || c == '"' || c == '\''
		|| c == ' ' || c == '=' || c == '\\' || c == '$' || c == '*')
	{
		return (1);
	}
	return (0);
}

static int	syntax_args(char **cmd)
{
	int		i;

	i = 1;
	if (ft_tablen(cmd) > 3)
	{
		ft_putendl_fd("42sh: setenv: Too many arguments", 2);
		return (0);
	}
	if (ft_tablen(cmd) < 3)
	{
		ft_putendl_fd("42sh: setenv: Too few arguments", 2);
		return (0);
	}
	return (1);
}

int			syntax_setenv(char **cmd)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (syntax_args(cmd) == 0)
		return (0);
	while (i < ft_tablen(cmd) && cmd[i])
	{
		j = 0;
		while (j < ft_strlen(cmd[i]) && cmd[i][j])
		{
			if (is_forbid(cmd[i][j]) && (ft_antislashed(cmd[i], j) == 0))
			{
				ft_putendl_fd("42sh: setenv: Syntax error", 2);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
