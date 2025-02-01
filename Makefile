NAME = push_swap
CC = cc
CFLAGS = -I. -I./libft
INCLUDE = push_swap.h

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

FILES = push_swap.c \
		parse.c \
		sort.c \
		stack.c \
		main.c 

OPS_FILES = operation/swap.c \
			operation/rotate.c \
			operation/reverse_rotate.c \
			operation/push.c

OBJS = $(FILES:.c=.o)
OPS_OBJS = $(OPS_FILES:.c=.o)

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS) $(OPS_OBJS)
		$(CC) $(OBJS) $(OPS_OBJS) $(LIBFT) -o $(NAME)

%.o:%.c $(INCLUDE)
		$(CC) $(CFLAGS) -I ./libft -c $< -o $@

clean:
		@$(MAKE) -C $(LIBFT_DIR) clean
		rm -rf $(OBJS) $(OPS_OBJS)

fclean: clean
		@$(MAKE) -C $(LIBFT_DIR) fclean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re