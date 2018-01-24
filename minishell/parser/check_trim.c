/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_trim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 19:46:04 by mda-cost          #+#    #+#             */
/*   Updated: 2016/11/03 21:03:52 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

char	**ft_arraytrim(char **array)
{
	int		i;
	char	*tmp;
	char	**new;
	int		len;

	tmp = NULL;
	new = NULL;
	i = 0;
	len = ft_tablen(array);
	if (!(new = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	ft_bzero((void *)new, sizeof(char *) * (len + 1));
	while (i < len)
	{
		tmp = array[i];
		new[i] = ft_strtrim(array[i]);
		free(tmp);
		tmp = NULL;
		i++;
	}
	free(array);
	array = NULL;
	return (new);
}

void	chk_rm_endchar(char *buffer, char c)
{
	if ((ft_strlen(buffer) > 0) && (buffer[ft_strlen(buffer) - 1] == c))
		buffer[ft_strlen(buffer) - 1] = '\0';
}

void	chk_spaces(char *str)
{
	int		i;
	char	jump;

	i = 0;
	jump = 0;
	while (i < ft_strlen(str) && str[i])
	{
		if ((jump = ft_char_to_jump(str[i])) > 0 && ft_antislashed(str, i) == 0)
			ft_jump(str, &i, jump);
		else if (str[i] == '\t' || str[i] == '\b' || str[i] == '\n' ||
				str[i] == '\r' || str[i] == '\f')
			str[i] = ' ';
		i++;
	}
}

void	chk_trim(t_shell *sh)
{
	char	*trimmed;

	trimmed = NULL;
	trimmed = ft_strtrim(sh->line);
	free(sh->line);
	sh->line = NULL;
	sh->line = trimmed;
}
