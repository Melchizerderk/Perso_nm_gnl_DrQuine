# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/07 16:47:32 by bcrespin          #+#    #+#              #
#    Updated: 2016/03/26 12:44:34 by bcrespin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc
CFLAG= -Wall -Werror -Wextra -g
SRC1= 
SRC2=

OBJ= $(SRC:.c=.o)
LIB= ./libft
NAME1= ft_nm
NAME2= ft_otool

all: ft_nm ft_otool

ft_nm:
	@(cd libft/ && $(MAKE))
	$(CC) -c $(CFLAG) -I headers -I $(LIB) -c $(SRC)
	$(CC) -o $(NAME) -L $(LIB) -lft $(OBJ)

ft_otool:
	@(cd libft/ && $(MAKE))
	$(CC) -c $(CFLAG) -I headers -I $(LIB) -c $(SRC2)
	$(CC) -o $(NAME) -L $(LIB) -lft $(OBJ)

clean:
	@(cd libft/ && $(MAKE) $@)
	rm -f $(OBJ)

fclean: clean
	@(cd libft/ && $(MAKE) $@)
	rm -f $(NAME)

re: fclean all
