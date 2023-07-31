# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plashkar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/14 17:00:19 by plashkar          #+#    #+#              #
#    Updated: 2023/07/20 16:51:58 by plashkar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = \
	ft_atoi.c ft_isascii.c ft_memchr.c ft_putchar_fd.c ft_strchr.c ft_strlcpy.c \
	ft_strrchr.c ft_bzero.c ft_isdigit.c ft_memcmp.c ft_putendl_fd.c \
	ft_strdup.c ft_strlen.c ft_strtrim.c ft_calloc.c ft_isprint.c ft_memcpy.c \
	ft_putnbr_fd.c ft_striteri.c ft_strmapi.c ft_substr.c ft_isalnum.c \
	ft_itoa.c ft_memmove.c ft_putstr_fd.c ft_strjoin.c ft_strncmp.c \
	ft_tolower.c ft_isalpha.c ft_memset.c ft_split.c ft_strlcat.c ft_strnstr.c \
	ft_toupper.c ft_printf_utils0.c ft_print_ptr.c ft_printf.c \
	ft_printf_utils1.c

BSRC = \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ = $(SRC:.c=.o)
BOBJS = $(BSRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -crs $(NAME) $(OBJ)

bonus: $(OBJ) $(BOBJS)
	ar -crs $(NAME) $(OBJ) $(BOBJS)

clean:
	rm -f $(OBJ) $(BOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean clean all re
