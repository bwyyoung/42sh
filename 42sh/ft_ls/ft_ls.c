/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 09:50:50 by byoung-w          #+#    #+#             */
/*   Updated: 2014/12/25 07:37:20 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				move_arg(char ***argv, int *numargs)
{
	*numargs = *numargs - 1;
	*argv += 1;
	return *numargs;
}

int				process_args(char ***argv, int *numargs)
{
	int		process_flags_ret;
	while ((numargs > 0) && (*argv[0][0] == '-') && ft_strlen(*argv[0]) > 1)
	{
		process_flags_ret = processflags(*argv[0]);
		if (!process_flags_ret)
			return (0);
		if (process_flags_ret == DOUBLE_DASH_STOP)
			return (1);
		*numargs = *numargs - 1;
		*argv += 1;
		if (!(**argv) || (*argv[0][0] != '-'))
			break;
	}
	return (1);
}

int				file_exist(char *filename)
{
	struct stat		buffer;
	return (stat(filename, &buffer) == 0);
}

static int		ls_args(char **argv, int numargs)
{
	if ((ft_strcmp(*argv, "-") == 0) && analysedir(*argv))
	{
		if (move_arg(&argv, &numargs) == 0)
			return (1);
	}
	else if (argv[0][0] == '-' && (!process_args(&argv, &numargs)))
		return (1);
	cmp_setcomparator();
	if (numargs <= 0)
		return (analysedir("."));
	analyse_params(numargs, argv);
	return (0);
}

int				main(int argc, char **argv)
{
	g_ls_flags.g_doubledash = false;
	g_ls_flags.g_cmp = &cmp_alpha;
	if (argc > 1)
	{
		argv++;
		return (ls_args(argv, argc - 1));
	}
	analysedir(".");
	return (0);
}
