/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:32:35 by mda-cost          #+#    #+#             */
/*   Updated: 2016/11/07 19:32:36 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

char		*ft_delete_var(char *s, int pos, int pos2)
{
	char	*new;
	char	*tmp1;

	new = NULL;
	tmp1 = NULL;
	tmp1 = ft_strndup(s, pos);
	if ((pos + pos2) < ft_strlen(s))
		new = ft_strjoin(tmp1, &s[pos + pos2]);
	else
		new = ft_strdup(tmp1);
	ft_freestr(tmp1);
	return (new);
}

char		*ft_var_replace(char *s, char *var, int pos, int pos2)
{
	char	*new;

	new = NULL;
	if (var != NULL)
		new = ft_include_var(s, var, pos, pos2);
	else
		new = ft_delete_var(s, pos, pos2);
	return (new);
}
