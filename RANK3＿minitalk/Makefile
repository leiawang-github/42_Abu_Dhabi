# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leia <leia@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 15:45:43 by leia              #+#    #+#              #
#    Updated: 2024/12/16 15:47:21 by leia             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= client.c server.c

OBJS	:= $(SRCS:%.c=%.o)

NAME	= minitalk

CC		= gcc
RM		= rm -f

CFLAGS 	= -Wall -Wextra -Werror

all:		${NAME}

%.o:	%.c
		${CC} ${CFLAGS} -Iprintf -c $? -o $@

${NAME}:	 server client

server:		server.o
		@make -C printf
		${CC} ${CFLAGS} $? -Lprintf -lftprintf -o server

client:		client.o
		@make -C printf
		${CC} ${CFLAGS} $? -Lprintf -lftprintf -o client

printf:
		make -C printf

clean:
			make clean -C printf
			${RM} ${OBJS}

fclean:		clean
			${RM} server client

re:			fclean all

.PHONY:		printf