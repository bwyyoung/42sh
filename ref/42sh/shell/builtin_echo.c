/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 19:26:50 by mda-cost          #+#    #+#             */
/*   Updated: 2016/11/03 19:26:53 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

static void	echo_cleanslash(char *str)
{
	int		i;
	char	*p;

	i = 0;
	p = NULL;
	while (str && i < ft_strlen(str))
	{
		while ((p = ft_strstr(str, "\\\"")) != NULL ||
				(p = ft_strstr(str, "\\\'")) != NULL)
		{
			ft_delchar(str, p);
			p = NULL;
		}
		i++;
	}
}

static int	is_quote(char c)
{
	if (c == '"' || c == '\'')
		return (1);
	return (0);
}

static void	echo_trimquotes(char *s)
{
	int	i;

	i = 0;
	if (ft_strlen(s) > 2)
	{
		while (i < ft_strlen(s))
		{
			if (is_quote(s[i]) && ft_antislashed(s, i) == 0)
			{
				tc_delchar(s, i);
				i = 0;
			}
			i++;
		}
	}
}

void		builtin_echo(t_env *e)
{
	int		i;
	int		backslash;

	i = 1;
	backslash = 1;
	if (ft_tablen(e->cmd) >= 1)
	{
		if (ft_tablen(e->cmd) >= 2 && ft_strcmp(e->cmd[1], "-n") == 0)
		{
			i++;
			backslash = 0;
		}
		while (i < ft_tablen(e->cmd) && e->cmd[i])
		{
			echo_trimquotes(e->cmd[i]);
			echo_cleanslash(e->cmd[i]);
			ft_putstr(e->cmd[i]);
			i++;
			if (i < ft_tablen(e->cmd) - 1)
				write(1, " ", 1);
		}
	}
	if (backslash)
		write(1, "\n", 1);
}
