/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/12/25 07:29:01 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh.h"

/*
** Solely responsible for printing of all
** envirionment variables
*/

int sh_env(t_shell *shell)
{
	t_env *env_var;

	env_var = NULL;
	if (!shell || !shell->env)
		fatal("There was an error in (sh_env)");
	env_var = shell->env;
	while (env_var)
	{
		if (env_var->name)
		{
			ft_putstr(env_var->name);
			ft_putstr("=");
		}
		if (env_var->value)
			ft_putendl(env_var->value);
		else
			ft_putendl("");
		env_var = env_var->next;
	}
	return (1);
}