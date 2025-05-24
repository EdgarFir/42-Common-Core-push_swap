NAME = push_swap

BONUS_NAME = checker

SRCS = push_swap.c push_swap_utils.c push_swap_checker_utils.c \
	   push_swap_operations.c push_swap_join_operations.c push_swap_calc_utils.c \
	   push_swap_stack_a_utils.c push_swap_stack_b_utils.c

BONUS_SRCS = checker_bonus.c checker_error_utils_bonus.c checker_utils_bonus.c \
			 checker_basic_opers_bonus.c checker_complex_opers_bonus.c

OBJS = ${SRCS:.c=.o}

BONUS_OBJS = ${BONUS_SRCS:.c=.o}

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

bonus: ${BONUS_NAME}

${BONUS_NAME}: ${BONUS_OBJS}
	make -C libft bonus
	${CC} ${CFLAGS} ${BONUS_OBJS} -I /libft -L libft/. -lft -o ${BONUS_NAME}

clean:
	make -C libft clean
	${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
	make -C libft fclean
	${RM} ${NAME} ${BONUS_NAME}

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re