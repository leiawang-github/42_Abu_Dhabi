# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leia <leia@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 15:45:43 by leia              #+#    #+#              #
#    Updated: 2024/12/18 13:38:11 by leia             ###   ########.fr        #
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
		${CC} ${CFLAGS} -Ift_printf -c $? -o $@

${NAME}:	 server client

server:		server.o
		@make -C ft_printf
		${CC} ${CFLAGS} $? -Lft_printf -lftprintf -o server

client:		client.o
		@make -C ft_printf
		${CC} ${CFLAGS} $? -Lft_printf -lftprintf -o client

printf:
		make -C ft_printf

clean:
			make clean -C ft_printf
			${RM} ${OBJS}

fclean:		clean
			${RM} server client

re:			fclean all

.PHONY:		ft_printf