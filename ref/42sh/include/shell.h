/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 18:16:52 by mda-cost          #+#    #+#             */
/*   Updated: 2016/04/04 15:10:40 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "../libft/includes/libft.h"
# include "../include/shell.h"
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/stat.h>

# define BUILTIN_ECHO 1
# define BUILTIN_ENV 2
# define BUILTIN_SETENV 3
# define BUILTIN_UNSETENV 4
# define BUILTIN_CD 5
# define BUILTIN_EXIT 6

typedef struct	s_env
{
	char		**env;
	char		**cmd;
	char		**paths;
	char		*final_path;
}				t_env;

t_env			*ft_init_env(t_env *e, char **environ);

int				ft_check_env(char **env);

void			ft_start(t_env *e);
void			ft_interpret(char **cmd, t_env *e);
char			*ft_return_key(char *key, char **env, int len);
char			*ft_return_rep(char *key, char **env, int len);
char			*ft_return_var(char *key, char **env, int len);

char			*ft_path_builder(char **cmd, t_env *e);

void			builtin_setenv(t_env *e);
void			ft_setenv(char *key, char *value, t_env *e);
int				syntax_setenv(char **cmd);
int				ft_find_key(char *key, char **env, int len_key);

void			builtin_unsetenv(t_env *e);
void			ft_unsetenv(char *key, t_env *e);

void			builtin_cd(t_env *e);

int				ft_add_history(char *line);
int				check_exec_command(char *path);
char			check_typefile(mode_t mode);

void			builtin_env(t_env *e);
char			**env_add_tmp(char **env, char *s);
void			builtin_echo(t_env *e);

int				ft_what_builtin(char **cmd);
void			ft_putarray_color(char **array);
#endif
