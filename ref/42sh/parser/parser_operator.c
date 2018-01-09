/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_operator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 20:58:25 by mda-cost          #+#    #+#             */
/*   Updated: 2016/10/20 20:58:27 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

static void	ft_jumper(char *s, int *i)
{
	char	c;

	c = 0;
	if ((s[*i] == '"' || s[*i] == '\'') && ft_antislashed(s, *i) == 0)
	{
		c = s[*i];
		*i = *i + 1;
		while (s[*i] && s[*i] != c)
			*i = *i + 1;
	}
}

static int	ft_prior_one(char *s, int *data)
{
	int		i;

	i = 0;
	while (s[i])
	{
		ft_jumper(s, &i);
		if (s[i] == ';')
		{
			data[POSITION] = i;
			data[OPERATOR] = COMMA;
			return (1);
		}
		i++;
	}
	return (0);
}

static int	ft_prior_two(char *s, int *data)
{
	int		i;

	i = 0;
	while (s[i])
	{
		ft_jumper(s, &i);
		if (s[i] == '|')
		{
			data[POSITION] = i;
			data[OPERATOR] = PIPE;
			return (1);
		}
		i++;
	}
	return (0);
}

static int	ft_prior_three(char *s, int *data)
{
	int		i;

	i = 0;
	while (s[i])
	{
		ft_jumper(s, &i);
		if (s[i] == '>' || s[i] == '<' || s[i] == '&')
		{
			data[POSITION] = i;
			data[OPERATOR] = ft_what_chevron(s, i);
			if (data[OPERATOR] == 0)
			{
				i++;
				continue ;
			}
			else
				return (data[OPERATOR]);
		}
		i++;
	}
	return (0);
}

int			ft_find_operator(char *command, int *data)
{
	int		i;

	i = 0;
	if (ft_prior_one(command, data) != 0)
		i = 1;
	else if (ft_prior_two(command, data) != 0)
		i = 2;
	else if (ft_prior_three(command, data) != 0)
		i = 3;
	return (i);
}
