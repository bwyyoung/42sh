/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/12/25 07:29:01 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

typedef struct s_shell		t_shell;

typedef struct				s_tkn
{
	char					*data;
	int						type;
	struct s_tkn			*left;
	struct s_tkn			*right;
}							t_tkn;

t_tkn						*tkn_new(char *data, int type);
int							tkn_new_to_back(t_tkn **lst, char *data, int type);
char						**split_command(char *cmd);
int							if_op_find_priority(char *s);
int							tokenize(t_shell **shell);
int							get_tokens(t_shell **shell);
void						tkn_move_args_to_start(t_tkn **dst, t_tkn **src);
void						reorganize_tokens(t_shell **shell);
void						move_pointers(t_tkn *init, t_tkn **start,
							t_tkn **ptr1, t_tkn **ptr2);
void						arrange_nodes_in_priority(t_shell **shell);
void						syn_error(void);
t_tkn						*build_tree(t_tkn *tree);
int							in_range(int i, int start, int end);
void						add_cmds(char ***cmds, char *cmd,
							int *offset, int *len);
int							is_op(char *c);
void						add_command(char ***cmds, char *cmd,
							int *offset, int *len);
t_tkn						*tkn_pre_last(t_tkn *lst);
t_tkn						*tkn_search_node(t_tkn *node, char *data);
t_tkn						*tkn_last(t_tkn *node);
void						skip_and_sort(t_tkn **tkns, t_tkn **lst_sep);
void						tkns_sort(t_tkn **begin_list);
int							prev_node_not_fd_aggr(t_tkn *start, t_tkn *end);
void						tkn_del(t_tkn *start, t_tkn **tkn);
#endif
