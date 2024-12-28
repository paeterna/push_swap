CC = cc

CFLAGS = -Wall -Wextra -Werror -Ilibft

NAME = push_swap

LIBFT = libft/libft.a

SRC = checks.c check_input.c halving_a.c halving_b.c helpers.c initializations.c \
	  main.c push.c reverse_rotate.c rotate.c sort_chunk_loop_a.c \
	  sort_chunk.c swap.c free_functions.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

$(LIBFT):
	@$(MAKE) -C libft

clean:
	rm -f $(OBJS)
	@$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
