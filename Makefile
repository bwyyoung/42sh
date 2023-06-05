# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/09 10:19:19 by byoung-w          #+#    #+#              #
#    Updated: 2015/04/29 20:13:26 by byoung-w         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	42sh
CC		=	gcc -Wall -Werror -Wdeprecated-declarations -Wextra
CCO		=	gcc -o
LIB		=	-L ft_printf/ -lftprintf -L libft/ -lft -L ft_ls/ -lftls
FLAGS	=	-Wall -Werror -Wextra

INC		=	-I libft/				\
			-I ft_printf/			\
			-I ft_ls/				\
			-I libs_42sh/termcap/	\

SRC		=	main.c							\
			42sh.c							\
			libs_42sh/termcap/termcap.c		\

OBJ		=	$(SRC:.c=.o) #interesting compilation method


all		: $(NAME)

$(NAME)	: $(OBJ)
	@make -C libft/
	@make -C ft_printf/
	@make -C ft_ls/
	@$(CC) $(FLAGS) $(INC) $(OBJ) -o $(NAME) $(LIB)

%.o: %.c
	@$(CC) -o $@ -c $< $(FLAGS)

clean	:
	@make -C libft/ clean
	@make -C ft_printf/ clean
	@make -C ft_ls/ clean
	@$(RM) $(OBJ)

fclean	: clean
	@make -C libft/ fclean
	@make -C ft_printf/ fclean
	@make -C ft_ls/ fclean
	@$(RM) $(NAME)

re		: fclean all

.PHONY : re fclean clean all