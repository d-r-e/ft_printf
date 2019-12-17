# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: darodrig <darodrig@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/09 13:22:42 by darodrig          #+#    #+#              #
#    Updated: 2019/12/17 10:31:23 by darodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDE = ft_printf.h

SRC = ft_libft.c  ft_pf.c  ft_printf.c  ft_put.c ft_utils.c ft_itoa_base.c \
	  ft_strdup.c ft_itoa.c ft_utoa.c ft_utils2.c ft_s.c ft_c.c ft_p.c ft_x.c \
	  ft_i.c ft_u.c ft_asterix.c

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

test:
	gcc -Wall -Wextra -Werror $(SRC) main.c
	./a.out | cat -e

