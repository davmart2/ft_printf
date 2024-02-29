# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davmart2 <davmart2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/27 15:08:21 by davmart2          #+#    #+#              #
#    Updated: 2024/01/28 11:35:54 by davmart2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


LIB = ar rcs

RM = rm -f

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
SRC = ft_characters.c ft_numbers.c ft_printf.c

OBJ = $(SRC:.c=.o)

INCLUDE = ft_printf.h

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	$(LIB) $(NAME) $(OBJ)

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
