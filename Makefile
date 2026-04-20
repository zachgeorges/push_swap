NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= main.c \
		  main_utils.c \
		  parsing.c \
		  parsing_utils.c \
		  stack_init_utils.c \
		  stack_utils.c \
		  swap_instructions.c \
		  push_instructions.c \
		  rotate_instructions.c \
		  reverse_rotate_instructions.c \
		  node_data.c \
		  algo.c

OBJS	= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
