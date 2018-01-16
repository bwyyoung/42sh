/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_command_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/12/25 07:29:01 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh.h"

void			add_command(char ***cmds, char *cmd, int *offset, int *len)
{
	char	*tmp;
	char	*tmp1;

	if (*len == 0)
		return ;
	tmp = ft_strndup(&cmd[*offset], *len);
	tmp1 = ft_strtrim(tmp);
	ft_arr_push(cmds, tmp1);
	ft_strdel(&tmp);
	ft_strdel(&tmp1);
}

static void		add_operator(char ***cmds, char *cmd, int *offset, int *len)
{
	int		len_op;
	char	*tmp;
	char	*tmp1;

	len_op = is_op(&cmd[*offset + *len]);
	if (!len_op || !(tmp = ft_strndup(&cmd[*offset + *len], len_op)))
		return ;
	ft_arr_push(cmds, tmp);
	tmp1 = ft_strtrim(tmp);
	ft_strdel(&tmp);
	ft_strdel(&tmp1);
	(*offset) += len_op;
}

void			add_cmds(char ***cmds, char *cmd, int *offset, int *len)
{
	add_command(cmds, cmd, offset, len);
	add_operator(cmds, cmd, offset, len);
	*offset += *len;
	*len = 0;
}
