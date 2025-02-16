MAND = get_next_line_utils.c get_next_line.c
BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c
OBJ = ${MAND:.c=.o}
OBJB = ${BONUS:.c=.o}
NAME = libget_next_line.a
LIBC = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJ}
	${LIBC} ${NAME} ${OBJ}

all: ${NAME}

bonus : ${NAME} ${OBJB}
	${LIBC} ${NAME} ${OBJB}
clean:
	${RM} ${OBJ} ${OBJB}

fclean: clean
	${RM} ${NAME} ${bonus}

re: fclean all

.PHONY : all bonus clean fclean re
