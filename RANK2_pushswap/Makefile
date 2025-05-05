NAME = push_swap
SRC = push_swap.c check_args.c process_args.c stack_ops_1.c \
	  stack_ops_2.c ft_libft_1.c ft_libft_2.c all_free.c radix_sort.c\
	  sort_small_stack_main.c sort_small_stack_helper.c push_into_stack.c\

OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
