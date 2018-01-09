/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 11:15:54 by mda-cost          #+#    #+#             */
/*   Updated: 2016/04/05 11:15:59 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <memory.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"
# include "../include/shell.h"
# include "../include/termcaps.h"

# define T_LEFT 91
# define T_RIGHT 92
# define ROOT 0
# define COMMA 1
# define PIPE 2
# define REDIR_R 3
# define APPEND 4
# define REDIR_L 5
# define HEREDOC 6
# define F_REDIR_R 7
# define F_REDIR_L 8

# define VARIABLE 1
# define BRACKETS 2

void			ft_parser(t_shell *sh, t_info *info);
void			ft_print_tree(t_node *tree, int deepness);

void			ft_freepaths(t_env *e);
void			ft_free_tree(t_node *tree);

void			ft_browser_func(t_info *info);

char			**ft_fill_operators(void);

int				ft_find_operator(char *command, int *data);
int				ft_what_chevron(char *s, int i);

void			ft_execdetect(t_node *node, t_info *info);
void			ft_now(char *path, char **cmd, char **env);

t_info			*ft_global(t_info *info);
void			ft_signal(void);
void			ft_signal_stop(int i);
void			ft_signal_resize(int i);

t_node			*ft_create_ast(char *command, char **ope, t_info *info);
void			ft_heredoc(char **splitted);
void			br_semicol(t_node *tree, t_info *info);
void			br_pipe(t_node *tree, t_info *info);

void			br_redirections(t_node *node, t_info *info);
void			redir_before_read(t_node *node);
void			redir_before_write(t_node *node);
void			redir_end_read(t_node *node);
void			redir_end_write(t_node *node);

void			ft_browse_start(t_node *root, t_info *info);
char			**ft_jumpsplit(char *s, char c);
void			ft_extract(t_node *node);
void			ft_update_fd(t_node *node);

int				ft_is_special(char c);
int				ft_antislashed(char *s, int i);
void			ft_cleanslash(char **array);
void			ft_delchar(char *line, char *ptr);
int				ft_trimquotes(char **array);
char			*ft_dollar(char *str, int pos, char **env);
void			ft_variable(t_node *node, char **env);
char			*ft_varseek(char *s, int pos, char **env);
char			*ft_substitution(char *s, int pos, char **env);
char			*ft_var_replace(char *s, char *var, int pos, int pos2);
char			*ft_delete_var(char *s, int pos, int pos2);
char			*ft_include_var(char *s, char *var, int pos, int pos2);

char			ft_char_to_jump(char c);
void			ft_jump(char *s, int *i, char jump);

void			builtin_exit(t_info *info);
void			ft_quit(t_info *info);

#endif
