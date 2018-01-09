/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/19 19:23:41 by mda-cost          #+#    #+#             */
/*   Updated: 2015/04/20 16:45:37 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

int		ft_check_env(char **env)
{
	int		state;

	state = 0;
	state = ft_find_key("HOME=", env, 5);
	if (state == 1)
		state = ft_find_key("PATH=", env, 5);
	if (state == 1)
		state = ft_find_key("PWD=", env, 4);
	if (state == 1)
		state = ft_find_key("OLDPWD=", env, 7);
	if (state == 1)
		state = ft_find_key("TERM=", env, 5);
	return (state);
}
