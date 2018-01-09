# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/27 16:06:32 by mda-cost          #+#    #+#              #
#    Updated: 2015/04/29 13:45:05 by mda-cost         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_minishell1

SRC_NAME	= ft_sh1.c init.c prompt.c start.c check_command.c prepare.c \
				command.c builtins.c builtin_setenv.c builtin_env.c utils.c \
				builtin_unsetenv.c check_env.c builtin_cd.c
SRC_PATH	= ./srcs/

INC_PATH	= ./include/ ./libft/includes/

OBJ_PATH	= ./objs/
OBJ_NAME	= $(SRC_NAME:.c=.o)

CMP			= gcc
FLAGS		= -Wall -Werror -Wextra

SRC			=	$(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ			=	$(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC			=	$(addprefix -I,$(INC_PATH))

LIB_NAME	= ./libft/libft.a

# colors

RED=\033[0;31m
LBLUE=\033[1;34m
CYAN=\033[0;36m
ORANGE=\033[0;33m
GREEN=\033[1;32m
NC=\033[0m

# ______

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft/
	@echo "${GREEN}Linking $(NAME)${NC}"
	@$(CMP) $(LIB_NAME) $(OBJ) -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo "${ORANGE}Compiling $^ into $@ ${NC}"
	@mkdir -p $(OBJ_PATH)
	@$(CMP) $(CFLAGS) $(INC) -o $@ -c $<

.PHONY: clean fclean re

clean:
	@rm -f $(OBJ)
	@make clean -C ./libft/
	@echo "ft_minishell1: objects deleted"

fclean: clean
	@make fclean -C ./libft/
	@rm -f $(NAME)


re: fclean all
