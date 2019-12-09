# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: darodrig <darodrig@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/09 13:22:42 by darodrig          #+#    #+#              #
#    Updated: 2019/12/09 16:45:07 by darodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDE = ft_printf.h

SRC = ft_libft.c  ft_pf.c  ft_printf.c  ft_put.c

OBJ = $(SRC:.c=.o)

$(NAME):
	$(CC) -c $(CFLAGS) $(SRC)
	ar rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean
