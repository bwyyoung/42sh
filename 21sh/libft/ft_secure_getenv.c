/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secure_getenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 22:13:47 by byoung-w          #+#    #+#             */
/*   Updated: 2017/04/05 14:39:51 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** my personal secured getenv
** takes in the env_var's name and returns its value
*/

char *ft_secure_getenv(const char *name)
{
	char *ret;

	ret = NULL;
	if ((ret = getenv(name)) == NULL)
		fatal("fatal environment error (ft_secure_getenv)");
	return (ret);
}
