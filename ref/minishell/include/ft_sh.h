/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 18:16:52 by mda-cost          #+#    #+#             */
/*   Updated: 2015/04/29 13:44:39 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH_H
# define FT_SH_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

typedef struct	s_env
{
	char		**env;
	char		**cmd;
	char		**paths;
}				t_env;

void			ft_print_test(char **tab);

t_env			*ft_init_env(t_env *e, char **environ);
char			**ft_copyenv(char **environ);
char			**ft_rescue_env(void);
void			ft_shell_lvl(t_env *e);

int				ft_check_env(char **env);

void			ft_start(t_env *e);
void			ft_cmd_line(char *cmd_line, t_env *e);
char			*ft_del_tab(char *cmd);
void			ft_print_test(char **tab);
void			ft_prompt(t_env *e);
void			ft_print_pwd_prompt(char *line);
char			*ft_return_key(char *key, char **env, int len);
void			ft_is_builtin_or_not(char **cmd, t_env *e);
void			ft_prepare(char **cmd, t_env *e);

int				ft_is_builtin(char **cmd);
void			ft_builtin(char **cmd, t_env *e);

int				ft_set_paths(t_env *e);
void			ft_check_cmd(char **cmd, t_env *e);
int				ft_check_dot_slash(char *cmd);
void			ft_check_access(char **cmd, t_env *e);
void			ft_fork_exec(char *path, char **cmd, t_env *e);

int				ft_syntax_setenv(char **cmd);
int				ft_pre_setenv(char **cmd, t_env *e);
int				ft_setenv(char *key, char *value, t_env *e);
int				ft_add_value_env(char *key_egal, char *val, t_env *e, int len);
int				ft_find_key(char *key, char **env, int len_key);
char			**ft_redo_env(char *key_egal, char *value, t_env *e);

int				ft_pre_unsetenv(char **cmd, t_env *e);
int				ft_syntax_unsetenv(char **cmd);
int				ft_unsetenv(char *key, t_env *e);
char			**ft_rebuild_env(t_env *e, char *key_egal, int len);

void			ft_cd(char **cmd, t_env *e);
int				ft_syntax_cd(char **cmd);
int				ft_change_rep(char *direction, t_env *e);
int				ft_back_rep(t_env *e);
char			*ft_return_rep(char *key, char **env, int len);
int				ft_back_home(t_env *e);

void			ft_start_env(char **cmd, t_env *e);
void			ft_builtin_env(char **cmd, t_env *e);
void			ft_env_var_tmp(char **cmd, t_env *e, int i);
char			**ft_env_add_tmp(char **env, char *s);
char			**ft_tabdup(char **env, int len);
char			**ft_only_cmd(char **cmd, t_env *e, int i);

void			*ft_freetab_and_null(char **tab);

#endif
