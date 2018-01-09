/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 13:58:15 by mda-cost          #+#    #+#             */
/*   Updated: 2016/11/03 21:02:55 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

void		ft_print_tree(t_node *tree, int deepness)
{
	if (!tree)
		return ;
	if (tree->left)
		ft_print_tree(tree->left, deepness + 1);
	ft_putstr("[");
	ft_putnbr(deepness);
	ft_putstr("] ");
	ft_putstr("tree->elem: ");
	ft_putendl_fd_color(tree->elem, 1, CYAN);
	if (tree->right)
		ft_print_tree(tree->right, deepness + 1);
}
