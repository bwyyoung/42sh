/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_operators.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:34:54 by mda-cost          #+#    #+#             */
/*   Updated: 2016/11/07 19:34:55 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

int			ft_is_special(char c)
{
	if (c == '<' || c == '>' || c == '&' || c == '|'
		|| c == '{' || c == '}' || c == '[' || c == ']'
		|| c == '(' || c == ')' || c == '"' || c == '\''
		|| c == ' ' || c == ';' || c == '\\')
	{
		return (1);
	}
	return (0);
}

static int	ft_is_fd_right(char *s, int i)
{
	int	ret;

	ret = 0;
	while (s[i] && ft_isdigit(s[i]) && (i < ft_strlen(s)))
	{
		if (ft_isalpha(s[i + 1]) == 1)
		{
			ret = 0;
			break ;
		}
		else if ((ft_is_special(s[i + 1]) == 1) || (s[i + 1] == 0))
		{
			ret = 1;
			break ;
		}
		i++;
	}
	return (ret);
}

static int	ft_is_fd_left(char *s, int i)
{
	int	ret;

	ret = (i == 0 && ft_isdigit(s[i])) ? 1 : 0;
	while (s[i] && i >= 1 && ft_isdigit(s[i]))
	{
		if (ft_isalpha(s[i - 1]) == 1)
		{
			ret = 0;
			break ;
		}
		else if (ft_is_special(s[i - 1]) == 1 ||
				(i == 1 && ft_isdigit(s[i - 1])))
		{
			ret = 1;
			break ;
		}
		i--;
	}
	return (ret);
}

static int	ft_precise_redirect(char *s, int i)
{
	int		right;
	int		left;

	right = 0;
	left = 0;
	if (i >= 1 && (i < (ft_strlen(s) - 2)))
	{
		if (ft_isdigit(s[i + 2]) == 1)
			right = ft_is_fd_right(s, i + 2);
		else if (s[i + 2] == '-')
			right = 1;
		if (ft_isdigit(s[i - 1]) == 1)
			left = ft_is_fd_left(s, i - 1);
		else if (s[i - 1] == ' ')
			left = 1;
		if (right == 0 || left == 0)
			return (F_REDIR_R);
	}
	return (0);
}

int			ft_what_chevron(char *s, int i)
{
	int		y;
	int		operator;

	y = 0;
	operator = 0;
	if (i > 0 && s[i] == '>')
	{
		if (s[i + 1] == '>')
			operator = APPEND;
		else if (s[i + 1] == '&')
			operator = ft_precise_redirect(s, i);
		else
			operator = REDIR_R;
	}
	else if (i > 0 && s[i] == '<')
	{
		if (s[i + 1] == '<')
			operator = HEREDOC;
		else if (s[i + 1] == '&')
			operator = F_REDIR_L;
		else
			operator = REDIR_L;
	}
	return (operator);
}
