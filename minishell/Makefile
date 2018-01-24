# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/27 16:06:32 by mda-cost          #+#    #+#              #
#    Updated: 2016/04/04 15:09:19 by mda-cost         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	21sh

INC_PATH	= ./include/ ./libft/includes/
OBJ_PATH	= ./objs/

SHELL_PATH	=	./shell/
SHELL_NAME	= 	main.c init.c prompt.c start.c check_command.c \
				builtins.c builtin_setenv.c builtin_env.c builtin_env2.c \
				utils.c \
				builtin_setenv_syntax.c \
				builtin_unsetenv.c check_env.c builtin_cd.c signal.c memory.c \
				history.c builtin_echo.c builtin_exit.c
SHELL_OBJ	=	$(SHELL_NAME:.c=.o)
SHELL_SRC	=	$(addprefix $(SHELL_PATH),$(SHELL_NAME))

TERM_PATH	=	./termcaps/
TERM_NAME	=	termcaps.c tc_alt.c tc_char.c tc_copy.c tc_cursor.c tc_del.c \
				tc_end.c tc_enter.c tc_home.c tc_init.c tc_main.c tc_term.c \
				tc_refresh.c tc_shift.c tc_unselect.c tc_ctrl_d.c tc_history.c \
				tc_init_list.c

TERM_OBJ	=	$(TERM_NAME:.c=.o)
TERM_SRC	=	$(addprefix $(TERM_PATH),$(TERM_NAME))

PARSER_PATH	=	./parser/
PARSER_NAME	=	br_semicol.c \
				br_detect.c \
				br_pipe.c \
				br_redirections.c \
				br_redir_functions.c \
				check_syntax.c check_operators.c check_trim.c \
				check_nextoperator.c \
				parser_operator.c \
				parser_operators.c \
				parser_print.c parser_init.c parser_heredoc.c \
				parser_tree.c parser_free.c \
				parser_execve.c \
				parser_split.c \
				parser_jump.c \
				parser_extract.c \
				parser_antislash.c \
				parser_variable.c \
				parser_variables.c \
				parser_substitution.c


PARSER_OBJ	=	$(PARSER_NAME:.c=.o)
PARSER_SRC	=	$(addprefix $(PARSER_PATH),$(PARSER_NAME))

SRC_NAME	=	$(SHELL_NAME) $(TERM_NAME) $(PARSER_NAME)
OBJ_NAME	=	$(SRC_NAME:.c=.o)
SRC			=	$(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ			=	$(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC			=	$(addprefix -I,$(INC_PATH))
LDFLAGS		=	-L libft -l ft -l termcap

CMP			= gcc
CFLAGS		= -Wall -Wextra -Werror -g

LIB_NAME	= ./libft/libft.a

# Print

ACTUAL		= $(words $(COUNT))
TOTAL		= $(words $(filter %.c,$(SRC_NAME)))
INCREMENT	= $(eval COUNT+=1)

PRINTINC	= $(INCREMENT) $(PRINT)
PRINT		= printf "\r $(REDB)%3s%%$(NC)\t -->>\t$(REDB)%-60s$(NC)\r" "$(shell echo $(ACTUAL)\*100\/$(TOTAL) | bc)" "$^"
PRINTDONE	= printf "\r $(GREENB)%3s%%$(NC)\t -->>\t$(GREENB)%-60s$(NC)\r" "$(shell echo $(ACTUAL)\*100\/$(TOTAL) | bc)" "$@"


# colors

RED=\033[0;31m
LBLUE=\033[0;34m
CYAN=\033[0;36m
ORANGE=\033[0;33m
GREEN=\033[0;32m
REDB=\033[31;1m
GREENB=\033[32;1m
NC=\033[0m

# ______

all: $(NAME)

$(NAME): $(OBJ)
		@make -C libft
		@$(CC) $(LDFLAGS) $(OBJ) -o $@ && $(PRINTDONE) && echo "" || exit

$(OBJ_PATH)%.o: $(SHELL_PATH)%.c ./include/shell.h
		@mkdir -p $(OBJ_PATH)
		@$(CC) $(CFLAGS) $(INC) -o $@ -c $< && $(PRINTINC) || exit

$(OBJ_PATH)%.o: $(TERM_PATH)%.c ./include/termcaps.h
		@mkdir -p $(OBJ_PATH)
		@$(CC) $(CFLAGS) $(INC) -o $@ -c $< && $(PRINTINC) || exit

$(OBJ_PATH)%.o: $(PARSER_PATH)%.c ./include/parser.h
		@mkdir -p $(OBJ_PATH)
		@$(CC) $(CFLAGS) $(INC) -o $@ -c $< && $(PRINTINC) || exit

.PHONY: clean fclean re

clean:
	@rm -f $(OBJ)
	@make clean -C ./libft/
	@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	@echo "${ORANGE}21sh:\tobjects removed${NC}"

fclean: clean
	@make fclean -C ./libft/
	@rm -f $(NAME)
	@echo "${ORANGE}21sh:\tbinary removed${NC}"

re: fclean all
