# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leiwang <leiwang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/06 11:27:45 by leiwang           #+#    #+#              #
#    Updated: 2024/08/10 18:15:28 by leiwang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

SRCS =	ft_printf.c	ft_putchar.c ft_putstr.c ft_put_signed_int.c ft_put_unsigned_int.c ft_puthex.c ft_puthex_with_pre.c ft_puthex_toupper.c 

		
OBJS = $(SRCS:.c=.o)

all:${NAME} 

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS) 

clean:
		$(RM) $(OBJS) $(OBJS_B)

fclean:clean
		$(RM) $(NAME)
		
re:clean all

.PHONY: bonus all clean fclean re