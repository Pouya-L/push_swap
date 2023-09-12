# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plashkar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/16 14:11:03 by plashkar          #+#    #+#              #
#    Updated: 2023/09/11 15:40:19 by plashkar         ###   ########.fr        #
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
	src/sort_complex_utils_0.c \
	src/sort_complex_utils_1.c \
	src/sort_complex_utils_2.c \
	src/sort_simple.c \
	src/sort_complex_algo.c \

CHECKER = \
	checker/checker_utils.C \
	checker/checker.C
	checker/push_and_swap_checker.c \
	checker/reverse_rotate_checker.c \
	checker/rotate_checker.c \

OBJ = $(SRC:.c=.o)

%.o: %.c
	@$(CC) $(FLAG) $(INCLUDE) -o $@ -c $<

all: $(NAME)

$(NAME): $(PUSH_LIB) $(OBJ)
	@echo "Compiling $@"
	@$(CC) $(FLAG) $(INCLUDE) src/main.c  $(OBJ) $(LIBFT_A) $(PUSH_LIB) -o $(NAME) > /dev/null
	@echo "push_swap has been created."

$(PUSH_LIB): $(OBJ)
	@echo "Creating $@"
	@make -C $(LIBFT_DIR) > /dev/null
	@ar rcs $(PUSH_LIB) $(OBJ) $(LIBFT_A) > /dev/null
	@echo The library push_swap.a has been created.

clean:
	@rm -f src/*.o
	@rm -f bonus/*.o
	@make -C $(LIBFT_DIR) clean > /dev/null
	@echo Object files have been deleted.


fclean: clean
	@rm -f $(PUSH_LIB)
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean > /dev/null
	@echo All created files have been deleted.

re: fclean all

.PHONY: fclean clean all re
