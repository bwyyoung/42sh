# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mda-cost <mda-cost@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/10 12:09:55 by mda-cost          #+#    #+#              #
#    Updated: 2015/04/16 17:58:52 by mda-cost         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRC 	= 	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
	   		ft_memmove.c ft_memchr.c ft_memcmp.c ft_memalloc.c \
	   		ft_memdel.c ft_error.c ft_swap.c \
	   		ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
	   		ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
	   		ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_strndup.c \
	   		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	   		ft_toupper.c ft_tolower.c \
	   		ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
	   		ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
	   		ft_strjoin.c ft_strtrim.c ft_strsplit.c \
	   		ft_itoa.c  ft_freestr.c \
	   		ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
	   		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	   		ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstlen.c \
	   		ft_nbrlen.c ft_tablen.c ft_arrayfree.c get_next_line.c ft_tabdup.c \
			ft_putendl_fd_color.c ft_putstr_fd_color.c ft_putarray.c

OBJ_PATH =	./objs/

OBJ_NAME = 	$(SRC:.c=.o);
OBJ		 =	$(addprefix $(OBJ_PATH),$(OBJ_NAME))

# Print

ACTUAL		= $(words $(COUNT))
TOTAL		= $(words $(filter %.c,$(SRC)))
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
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME) && $(PRINTDONE) && echo "" || exit

$(OBJ_PATH)%.o: %.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -I./includes -c $< -o $@ && $(PRINTINC) || exit

.PHONY: clean fclean re

clean:
	@$(RM) $(OBJ_PATH)
	@echo "${CYAN}libft:\tobjects removed${NC}"

fclean: clean
	@$(RM) $(NAME)
	@echo "${CYAN}libft:\tlibft.a removed${NC}"

re: fclean all
