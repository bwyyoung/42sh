/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 16:08:50 by mda-cost          #+#    #+#             */
/*   Updated: 2016/04/04 16:08:58 by mda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMCAPS_H
# define TERMCAPS_H

# include "../libft/includes/libft.h"
# include "../include/shell.h"
# include <unistd.h>
# include <stdlib.h>
# include <termios.h>
# include <term.h>
# include <termcap.h>
# include <signal.h>
# include <sys/ioctl.h>
# include <fcntl.h>

# define TERM_SIZE		2048
# define LINE_SIZE		2048
# define UP				"\x1B[A"
# define DOWN			"\x1B[B"
# define RIGHT			"\x1B[C"
# define LEFT			"\x1B[D"

# define END			"\x1B[F"
# define HOME			"\x1B[H"

# define DEL_RIGHT		"\x1B[3~"
# define DEL_LEFT		"\x7F"

# define SHIFT_UP		"\x1B[1;2A"
# define SHIFT_DOWN		"\x1B[1;2B"
# define SHIFT_RIGHT	"\x1B[1;2C"
# define SHIFT_LEFT	 	"\x1B[1;2D"

# define CROSS_RIGHT 	1
# define CROSS_LEFT 	2

# define ALT_RIGHT		"\x1B\x1B[C"
# define ALT_LEFT		"\x1B\x1B[D"

# define ALT_C			"ç"
# define ALT_V			"√"
# define ALT_X			"≈"

# define ENTER			"\n"
# define ESCAPE			"\x1B"

# define OPERATOR		0
# define POSITION		1

typedef struct		s_hist
{
	char			*cmd;
	struct s_hist	*next;
	struct s_hist	*prev;
}					t_hist;

typedef struct		s_node
{
	char			*elem;
	int				type;
	int				stdin;
	int				stdout;
	int				stderr;
	int				fd_from;
	int				fd_to;
	char			**cmd;
	struct s_node	*left;
	struct s_node	*right;
}					t_node;

typedef struct		s_caps
{
	char			*go_right;
	char			*go_left;
	char			*go_up;
	char			*go_down;
	char			*go_home;
	char			*go_to_x;
	char			*delete;
	char			*insert_mode;
	char			*leave_insert;
	char			*go_standout;
	char			*leave_standout;
	char			*clear_lines;
	char			*ding;
}					t_caps;

typedef struct		s_shell
{
	char			*line;
	int				x;
	int				y;
	int				s_x;
	int				s_y;
	int				select;
	char			*prompt;
	int				prompt_len;
	struct winsize	ws;
	char			*copybuff;
	t_caps			*caps;
	void			(*tab_key[21])(char *, struct s_shell *, t_caps *);
	int				exec;
	int				exit;
	int				exit_value;
	t_hist			*history;
}					t_shell;

typedef struct		s_info
{
	t_env			*e;
	t_shell			*sh;
	void			(*tab_browser[10])(t_node *, struct s_info *);
}					t_info;

int					ft_termcaps_get_line(char *line, t_shell *sh);

int					ft_valid_term(t_info *info);
void				ft_set_term(void);
void				ft_restore_term(void);
int					ft_loop(t_info *info);

t_shell				*ft_shell_malloc();
int					tc_keydetect(char *key);

t_hist				*ft_add_head_double(t_hist *head, char *line);

void				ft_free_list(t_hist *list);
void				ft_free_info(t_info *info);
void				ft_free_sh(t_shell *sh);
void				ft_free_env(t_env *e);

void				ft_reset_prompt(t_shell *sh);

void				tc_cursor_right(char *line, t_shell *sh, t_caps *caps);
void				tc_cursor_left(char *line, t_shell *sh, t_caps *caps);
void				tc_move_right(char *line, t_shell *sh, t_caps *caps);
void				tc_move_left(char *line, t_shell *sh, t_caps *caps);
void				tc_home(char *line, t_shell *sh, t_caps *caps);
void				tc_end(char *line, t_shell *sh, t_caps *caps);
void				tc_shift_up(char *line, t_shell *sh, t_caps *caps);
void				tc_shift_down(char *line, t_shell *sh, t_caps *caps);
void				tc_alt_right(char *line, t_shell *sh, t_caps *caps);
void				tc_alt_left(char *line, t_shell *sh, t_caps *caps);

t_hist				*ft_load_history(void);
void				tc_up(char *line, t_shell *sh, t_caps *caps);
void				tc_down(char *line, t_shell *sh, t_caps *caps);

void				tc_shift_right(char *line, t_shell *sh, t_caps *caps);
void				tc_shift_left(char *line, t_shell *sh, t_caps *caps);

void				tc_insert_char(char *line, char *key, t_shell *sh);
void				tc_addchar(char *line, char c, int x);
void				tc_delchar(char *line, int x);
void				tc_del_right(char *line, t_shell *sh, t_caps *caps);
void				tc_del_left(char *line, t_shell *sh, t_caps *caps);
void				tc_delete_selection(char *line, t_shell *sh, int x);

void				tc_copy(char *line, t_shell *sh, t_caps *caps);
void				tc_paste(char *line, t_shell *sh, t_caps *caps);
void				tc_cut(char *line, t_shell *sh, t_caps *caps);
void				tc_unselect(char *line, t_shell *sh, int x);
void				ft_check_unselect(char *line, t_shell *sh, int x);

void				tc_fake_char(t_shell *sh);
void				tc_char_print(char *line, t_shell *sh, t_caps *caps);

void				ft_refresh(char *line, t_shell *sh, t_caps *caps);
void				tc_full_refresh(char *line, t_shell *sh, int x);
void				tc_enter(char *line, t_shell *sh, t_caps *caps);

void				tc_print(char *line, t_shell *sh, t_caps *caps);

int					ft_ctrl_d(char *line, t_shell *sh);

int					ft_syntax(t_shell *sh);
char				**ft_arraytrim(char **array);
void				chk_spaces(char *str);
void				chk_rm_endchar(char *buffer, char c);
void				chk_trim(t_shell *sh);
int					chk_operators(char *line);
int					chk_nextoperator(char *line);
int					chk_nextchar(char *str, char c);
int					chk_checking(char *line, int len, int i, char c);

#endif
