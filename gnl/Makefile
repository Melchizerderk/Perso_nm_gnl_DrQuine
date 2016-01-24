# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/07 16:47:32 by bcrespin          #+#    #+#              #
#    Updated: 2015/04/11 12:06:48 by bcrespin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc
CFLAG= -Wall -Werror -Wextra -g
SRC= 

OBJ= $(SRC:.c=.o)
LIB= ./libft
NAME= ft_script

all:$(NAME)

$(NAME):
	@(cd libft/ && $(MAKE))
	$(CC) -c $(CFLAG) -I headers -I $(LIB) -c $(SRC)
	$(CC) -o $(NAME) -L $(LIB) -lft $(OBJ) -L /usr/lib -ltermcap

clean:
	@(cd libft/ && $(MAKE) $@)
	rm -f $(OBJ)

fclean: clean
	@(cd libft/ && $(MAKE) $@)
	rm -f $(NAME)

re: fclean all
