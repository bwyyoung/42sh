/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 21:03:11 by mda-cost          #+#    #+#             */
/*   Updated: 2016/11/03 21:03:12 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

static char	*ft_varname(char *s, int i)
{
	char	*var;
	int		len;
	int		start;

	var = NULL;
	len = 0;
	start = i;
	while (i < ft_strlen(s) && ft_isalpha(s[i]))
	{
		i++;
		len++;
	}
	var = ft_strsub(s, start, len);
	return (var);
}

char		*ft_include_var(char *s, char *var, int pos, int pos2)
{
	char	*tmp1;
	char	*tmp2;
	char	*tmp3;
	char	*new;

	tmp1 = NULL;
	tmp2 = NULL;
	tmp3 = NULL;
	new = NULL;
	tmp1 = ft_strndup(s, pos);
	tmp2 = ft_strjoin(tmp1, var);
	tmp3 = ft_strdup(&s[pos + pos2]);
	new = ft_strjoin(tmp2, tmp3);
	ft_freestr(tmp1);
	ft_freestr(tmp2);
	ft_freestr(tmp3);
	return (new);
}

char		*ft_varseek(char *s, int pos, char **env)
{
	char	*varname;
	char	*var;
	char	*new;

	varname = NULL;
	var = NULL;
	new = NULL;
	varname = ft_varname(s, pos + 1);
	var = ft_return_var(varname, env, ft_strlen(varname));
	new = ft_var_replace(s, var, pos, ft_strlen(varname) + 1);
	ft_freestr(varname);
	ft_freestr(s);
	varname = NULL;
	s = NULL;
	var = NULL;
	return (new);
}

char		*ft_dollar(char *str, int pos, char **env)
{
	if (str[pos + 1] == '{')
		str = ft_substitution(str, pos, env);
	else
		str = ft_varseek(str, pos, env);
	return (str);
}

void		ft_variable(t_node *node, char **env)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strdup(node->elem);
	while (i < ft_strlen(str) && str[i])
	{
		if (str[i] == '\'' && ft_antislashed(str, i) == 0)
			ft_jump(str, &i, '\'');
		if (str[i] == '\0')
			break ;
		if (str[i] == '$' && str[i + 1])
		{
			str = ft_dollar(str, i, env);
			i = 0;
		}
		else
			i++;
	}
	ft_freestr(node->elem);
	node->elem = str;
}
