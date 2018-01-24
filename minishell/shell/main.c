/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 18:14:15 by mda-cost          #+#    #+#             */
/*   Updated: 2016/04/04 14:48:43 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

static int		ft_term_routines(t_info *info)
{
	int				ret;
	struct termios	tios;

	ret = 1;
	if (ft_valid_term(info) != 0)
	{
		ret = tcgetattr(0, &tios);
		tios.c_lflag &= ~(ICANON);
		tios.c_lflag &= ~(ECHO);
		ret = tcsetattr(0, TCSADRAIN, &tios);
		return (ret);
	}
	else
		return (-1);
}

static t_info	*ft_init_info(char **environ)
{
	t_info	*info;

	info = NULL;
	if (!(info = (t_info *)malloc(sizeof(t_info))))
		return (NULL);
	ft_bzero((void *)info, sizeof(t_info));
	info->e = ft_init_env(info->e, environ);
	ft_browser_func(info);
	if (info->e == NULL)
		ft_error("error: bad env");
	info->sh = NULL;
	if (ft_term_routines(info) == -1)
		ft_error("terminal init: error");
	return (info);
}

int				main(int argc, char **argv, char **environ)
{
	t_info	*info;
	int		exit_value;

	info = NULL;
	exit_value = 0;
	(void)argv;
	if (argc > 1)
		ft_error("No argument accepted");
	if (getenv("TERM") == NULL)
		ft_error("\033[0;33;40mError: var TERM not found\033[0m");
	info = ft_init_info(environ);
	ft_global(info);
	ft_signal();
	exit_value = ft_loop(info);
	ft_quit(info);
	return (exit_value);
}
