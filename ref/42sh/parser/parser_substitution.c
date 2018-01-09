/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_substitution.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 21:03:01 by mda-cost          #+#    #+#             */
/*   Updated: 2016/11/03 21:03:02 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

static char	*ft_subname(char *s, int i)
{
	char	*var;
	int		len;
	int		start;

	var = NULL;
	len = 0;
	start = i;
	while (i < ft_strlen(s) && s[i] != '}')
	{
		i++;
		len++;
	}
	if (len > 0 && s[i] == '}')
		var = ft_strsub(s, start, len);
	return (var);
}

char		*ft_substitution(char *s, int pos, char **env)
{
	char	*varname;
	char	*var;
	char	*new;

	varname = NULL;
	var = NULL;
	new = NULL;
	varname = ft_subname(s, pos + 2);
	if (varname != NULL)
	{
		var = ft_return_var(varname, env, ft_strlen(varname));
		new = ft_var_replace(s, var, pos, ft_strlen(varname) + 3);
	}
	else
		ft_putstr_fd("42sh: bad substitution", 2);
	ft_freestr(varname);
	ft_freestr(s);
	varname = NULL;
	s = NULL;
	var = NULL;
	return (new);
}
