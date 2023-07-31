# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 15:16:55 by plashkar          #+#    #+#              #
#    Updated: 2023/07/31 15:24:08 by plashkar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
CC = cc
FLAG = -Wall -Werror -Wextra

SRC = push_swap.c push_swap_utils.c

OBJ = (SRC:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	cd libft; make
	cp $(LIBFT) $(NAME)
	ar -crs $(NAME) $(OBJ) $(LIBFT)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean:
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: fclean clean all re
