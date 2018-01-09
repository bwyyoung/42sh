/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_t.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 09:50:50 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/03 11:22:41 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		*file_time_bigt(char *time)
{
	char	*time1;

	time1 = ft_strsub(time, 4, ft_strlen(time) - 5);
	return (time1);
}

static char		*file_time_yyyy(char *time)
{
	char	*time1;
	char	*year;
	int		year_pos;
	size_t	len;
	char	new_time[ft_strlen(time)];

	len = ft_strlen(time);
	year_pos = (int)(ft_strrchr(time, ' ') + 1 - time);
	year = time + year_pos;
	year[len - year_pos - 1] = '\0';
	time1 = time + 4;
	time1[len - 4] = '\0';
	time = time1;
	time[7] = '\0';
	ft_strjoin_opti(ft_strjoin_opti(time, " ", new_time), year, new_time);
	time = ft_strdup(new_time);
	return (time);
}

static char		*file_time_6m(char *time)
{
	char	*time1;
	size_t	i;
	size_t	j;

	j = 0;
	i = ft_strlen(time);
	time = time + 4;
	time[ft_strlen(time) - 5] = '\0';
	while (time[i + 1] != ':')
		i--;
	time1 = ft_memalloc(i + 1);
	while (j <= i)
	{
		time1[j] = time[j];
		j++;
	}
	time1[j] = '\0';
	return (time1);
}

static char		*file_time_mode(t_stat *filestat, t_btree **node,
char *mtime, time_t mtime2)
{
	time_t	current_time;

	current_time = time(NULL);
	if (g_ls_flags.g_ls_display_bigu && g_ls_flags.g_lsl)
	{
		mtime = ctime(&filestat->st_birthtime);
		mtime2 = (*node)->btime;
	}
	if (g_ls_flags.g_ls_display_u && g_ls_flags.g_lsl)
	{
		mtime = ctime(&filestat->st_atime);
		mtime2 = (*node)->atime;
	}
	if (g_ls_flags.g_ls_display_c && g_ls_flags.g_lsl)
	{
		mtime = ctime(&filestat->st_ctime);
		mtime2 = (*node)->ctime;
	}
	if (g_ls_flags.g_lsbigt)
		return (file_time_bigt(mtime));
	else if ((current_time - SIX_M <= mtime2) &&
(mtime2 <= current_time))
		return (file_time_6m(mtime));
	else
		return (file_time_yyyy(mtime));
}

char			*file_time(t_stat *filestat, t_btree **node)
{
	char	*mtime;
	time_t	mtime2;

	(*node)->btime = filestat->st_birthtimespec.tv_sec;
	(*node)->ctime = filestat->st_ctimespec.tv_sec;
	(*node)->atime = filestat->st_atimespec.tv_sec;
	(*node)->mtime = filestat->st_mtimespec.tv_sec;
	mtime = ctime(&filestat->st_mtime);
	mtime2 = (*node)->mtime;
	return (file_time_mode(filestat, node, mtime, mtime2));
}
