# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/16 14:11:03 by plashkar          #+#    #+#              #
#    Updated: 2023/08/31 19:19:11 by plashkar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

FLAG = -Wall -Werror -Wextra -g

INCLUDE = -Iincludes

LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a

PUSH_LIB = push_swap.a

SRC = \
	src/list_utils_0.c \
	src/list_utils_1.c \
	src/swap.c \
	src/rotate.c \
	src/reverse_rotate.c \
	src/push.c \
	src/stack_init.c \
	src/check_args.c \
	src/sort_utils.c \
	src/sort_complex_utils.c \
	src/sort_simple.c \


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(PUSH_LIB) $(OBJ)
	@$(CC) $(FLAG) $(INCLUDE) src/main.c  $(OBJ) $(LIBFT_A) $(PUSH_LIB) -o $(NAME)
	@echo push_swap has been created.

$(PUSH_LIB): $(OBJ)
	@make -C $(LIBFT_DIR)
	@ar rcs $(PUSH_LIB) $(OBJ) $(LIBFT_A)
	@echo push_swap.a has been created.

clean:
	@rm -f src/*.o
	@rm -f bonus/*.o
	@make -C $(LIBFT_DIR) clean
	@echo Object files have been deleted.


fclean: clean
	@rm -f $(PUSH_LIB)
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo All created files have been deleted.

re: fclean all

.PHONY: fclean clean all re
