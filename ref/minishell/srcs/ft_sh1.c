/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 18:14:15 by mda-cost          #+#    #+#             */
/*   Updated: 2015/04/29 13:44:30 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int		main(int argc, char **argv, char **environ)
{
	t_env	*e;

	e = NULL;
	(void)argv;
	if (argc > 1)
		ft_error("No argument accepted");
	e = ft_init_env(e, environ);
	return (0);
}
