/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/12/25 07:29:01 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TERMCAP_H__
# define __TERMCAP_H__

void		tc_start(void);
void		tc_screen_render(void);
void		tc_screen_clear(void);

void		tc_write_line(char *c);
void		tc_del_line(void);

void		tc_write_char(char c);
void		tc_del_char(void);

void		tc_cursor_move(int direction);
void		tc_end(void);
#endif