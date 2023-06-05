# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/09 10:19:19 by byoung-w          #+#    #+#              #
#    Updated: 2014/12/10 16:19:13 by byoung-w         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	=	libftls.a
NAME_LIBFT = ../libft/libft.a
CC		=	gcc
ARRC	=	ar rc
RANLIB	=	ranlib
LIB		=	-L ../libft/ -lft
FLAGS	=	-c -Wall -Werror -Wextra

INC		=	../libft/includes/

C_FILES	= ft_ls.c
C_FILES	+= ft_ls_l.c
C_FILES	+= ft_ls_error.c
C_FILES	+= ft_ls_flags.c
C_FILES	+= ft_ls_cmp.c
C_FILES	+= ft_ls_cmp2.c
C_FILES	+= ft_ls_t.c
C_FILES	+= ft_ls_util.c
C_FILES	+= btree_insert_node.c
C_FILES	+= btree_create_node.c
C_FILES	+= btree_delete_tree.c
C_FILES	+= btree_print.c
C_FILES	+= btree_search_item.c
C_FILES += ft_ls_r.c
C_FILES += ft_ls_dir.c
C_FILES += ft_ls_params.c
C_FILES += ft_ls_opti.c

O_FILES	= ft_ls.o
O_FILES	+= ft_ls_l.o
O_FILES	+= ft_ls_error.o
O_FILES	+= ft_ls_flags.o
O_FILES	+= ft_ls_cmp.o
O_FILES	+= ft_ls_cmp2.o
O_FILES	+= ft_ls_t.o
O_FILES	+= ft_ls_util.o
O_FILES	+= btree_insert_node.o
O_FILES	+= btree_create_node.o
O_FILES	+= btree_delete_tree.o
O_FILES	+= btree_print.o
O_FILES	+= btree_search_item.o
O_FILES += ft_ls_r.o
O_FILES += ft_ls_dir.o
O_FILES += ft_ls_params.o
O_FILES += ft_ls_opti.o

all		: $(NAME)

$(NAME)	:
	@$(CC) $(FLAGS) -c $(C_FILES) -I $(INC)
	@$(ARRC) $(NAME) $(O_FILES) ../libft/*.o
	@$(RANLIB) $(NAME)

clean	:
	@/bin/rm -f $(O_FILES)

fclean	: clean
	@/bin/rm -f $(NAME)

re		: fclean all
