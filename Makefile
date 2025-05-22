NAME = push_swap

SRCS = push_swap.c push_swap_utils.c push_swap_checker_utils.c \
	   operations.c join_operations.c calc_utils.c stack_a_utils.c stack_b_utils.c

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

INCLUDE_LIBFT = -I libft/.

LIBFT_LIB = -L libft/. -lft

all: ${NAME}

.c.o:
	${CC} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	make -C libft bonus
	${CC} ${CFLAGS} ${OBJS} -I /libft -L libft/. -lft -o ${NAME}

clean:
	make -C libft clean
	${RM} ${OBJS}

fclean: clean
	make -C libft fclean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re