MAND = ft_printf.c ft_putex.c ft_putnbr.c ft_putpoint.c ft_putnbruns.c
OBJ = ${MAND:.c=.o}
NAME = libftprintf.a
LIBC = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJ}
	${LIBC} ${NAME} ${OBJ}

all: ${NAME}

clean:
	${RM} ${OBJ} 

fclean: clean
	${RM} ${NAME} 

re: fclean all

.PHONY : all clean fclean re
