/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 12:16:59 by mda-cost          #+#    #+#             */
/*   Updated: 2015/05/12 12:17:08 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_tabdup(char **tab)
{
	int		i;
	char	**n_tab;

	n_tab = (char **)malloc(sizeof(char *) * ((ft_tablen(tab) + 1)));
	if (!n_tab)
		return (NULL);
	ft_bzero((void *)n_tab, sizeof(char *) * ((ft_tablen(tab) + 1)));
	i = 0;
	while (tab[i])
	{
		n_tab[i] = ft_strdup(tab[i]);
		i++;
	}
	n_tab[i] = NULL;
	return (n_tab);
}
