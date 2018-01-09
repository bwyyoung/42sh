/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 09:50:50 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/03 11:22:41 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		checkflag_bonus_2(char flag)
{
	if (flag == 'o')
	{
		g_ls_flags.g_lso = 1;
		g_ls_flags.g_lsone = 0;
	}
	else if (flag == 'F')
	{
		g_ls_flags.g_lsbigf = 1;
		g_ls_flags.g_lsp = 0;
	}
	else if (flag == 'U')
	{
		g_ls_flags.g_lsbigu = 1;
		g_ls_flags.g_ls_display_bigu = 1;
	}
	else if (flag == 'u')
	{
		g_ls_flags.g_lsu = 1;
		g_ls_flags.g_ls_display_u = 1;
	}
	else
		return (0);
	return (1);
}

int				checkflag_bonus_1(char flag)
{
	if ((flag == 'U') || (flag == 'u') || (flag == 'S') || (flag == 'c'))
		reset_sort();
	if ((flag == 'U') || (flag == 'u') || (flag == 'c'))
		reset_display();
	if (flag == 'g')
	{
		g_ls_flags.g_lsg = 1;
		g_ls_flags.g_lsone = 0;
	}
	else if (flag == 'd')
		g_ls_flags.g_lsd = 1;
	else if (flag == 'S')
		g_ls_flags.g_lsbigs = 1;
	else if (flag == 'p')
		g_ls_flags.g_lsp = 1;
	else if (flag == 'c')
	{
		g_ls_flags.g_ls_display_c = 1;
		g_ls_flags.g_lsc = 1;
	}
	else if (flag == 'T')
		g_ls_flags.g_lsbigt = 1;
	else
		return (checkflag_bonus_2(flag));
	return (1);
}

int				checkflag(char flag)
{
	if (flag == 'a')
		g_ls_flags.g_lsa = 1;
	else if (flag == 'l')
	{
		g_ls_flags.g_lsone = 0;
		g_ls_flags.g_lsl = 1;
	}
	else if (flag == 'r')
		g_ls_flags.g_lsr = 1;
	else if (flag == 'R')
		g_ls_flags.g_lsbigr = 1;
	else if (flag == 't')
		g_ls_flags.g_lst = 1;
	else if (flag == '1')
	{
		g_ls_flags.g_lsone = 1;
		g_ls_flags.g_lsl = 0;
	}
	else if (flag == 'A')
		g_ls_flags.g_lsbiga = 1;
	else if (flag == 'f')
		g_ls_flags.g_lsf = 1;
	else
		return (checkflag_bonus_1(flag));
	return (1);
}

int				processflags(char *flags)
{
	int		i;

	i = 1;
	if (!ft_strcmp(flags, "--") || !ft_strcmp(flags, "---"))
	{
		if (!g_ls_flags.g_doubledash)
			return (g_ls_flags.g_doubledash = true);
		return (DOUBLE_DASH_STOP);
	}
	if (file_exist(flags))
		return (DOUBLE_DASH_STOP);
	while (flags[i] != '\0')
	{
		if ((flags[i] == '.') || !checkflag(flags[i]))
			return (error_illegalopt(flags[i]));
		i++;
	}
	return (1);
}

void			cmp_setcomparator(void)
{
	//printf("Comparator %i %i %i %i\n", g_ls_flags.g_lsu, g_ls_flags.g_lsbigu,
	//	   g_ls_flags.g_lsc, g_ls_flags.g_lsbigt);
	g_ls_flags.g_cmp = &cmp_alpha;
	if (!g_ls_flags.g_lsl && !g_ls_flags.g_lst)
		g_ls_flags.g_lsu = false;
	if (g_ls_flags.g_lst)
		g_ls_flags.g_cmp = &cmp_mtime;
	if (g_ls_flags.g_lsu)
		g_ls_flags.g_cmp = &cmp_atime;
	if (g_ls_flags.g_lsc && g_ls_flags.g_lst)
		g_ls_flags.g_cmp = &cmp_ctime;
	if (g_ls_flags.g_lsbigu && g_ls_flags.g_lst)
		g_ls_flags.g_cmp = &cmp_btime;
	if (g_ls_flags.g_lsbigs)
		g_ls_flags.g_cmp = &cmp_size;
	if (g_ls_flags.g_lsf)
	{
		g_ls_flags.g_lst = false;
		g_ls_flags.g_lsa = true;
		g_ls_flags.g_cmp = &cmp_nosort;
	}
	if (g_ls_flags.g_lsg && !g_ls_flags.g_lsone)
		g_ls_flags.g_lsl = 1;
	if (g_ls_flags.g_lso && !g_ls_flags.g_lsone)
		g_ls_flags.g_lsl = 1;
}
