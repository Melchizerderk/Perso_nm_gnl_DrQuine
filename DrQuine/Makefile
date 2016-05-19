# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcrespin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/19 11:08:42 by bcrespin          #+#    #+#              #
#    Updated: 2016/05/19 11:22:13 by bcrespin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= clang
CFLAG= -Wall -Werror -Wextra
SRC1= Colleen.c
SRC2= Grace.c
SRC3= Sully.c

NAME1= Colleen
NAME2= Grace
NAME3= Sully

all: Colleen Grace Sully

Colleen:
	$(CC) $(CFLAG) -o $(NAME1) $(SRC1)

Grace:
	$(CC) $(CFLAG) -o $(NAME2) $(SRC2)

Sully:
	$(CC) $(CFLAG) -o $(NAME3) $(SRC3)

fclean:
	rm -f $(NAME1) $(NAME2) $(NAME3)
