/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 00:28:49 by byoung-w          #+#    #+#             */
/*   Updated: 2017/03/10 00:29:55 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_word_count(char const *s, char c)
{
	int	i;
	int	wc;
	int	found;

	i = 0;
	wc = 0;
	found = 0;
	while (s[i])
	{
		if (s[i] == c)
			found = 0;
		else
		{
			if (found == 0)
				wc++;
			found = 1;
		}
		i++;
	}
	return (wc);
}
