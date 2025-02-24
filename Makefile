FILES = so_long.c misc.c printmap.c play.c checks.c	
OBJ = $(FILES:.c=.o)
NAME = so_long
MLX_PATH = minilibx/
MLX_LIB = $(MLX_PATH)libmlx.a
LIBFT_PATH = libfta/
LIBFT_LIB = $(LIBFT_PATH)libft.a
CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -lX11 -lXext -Lminilibx -lmlx 
CC = cc
RM = rm -f

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c -o $@ $<

all: adittionallibs $(NAME)

adittionallibs:
	@make -C $(MLX_PATH) all
	@make -C $(LIBFT_PATH) all

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ) $(MLX_LIB) $(LIBFT_LIB) -o $(NAME)
	
clean:
	make -C $(MLX_PATH) clean
	make -C $(LIBFT_PATH) clean
	${RM} $(OBJ)

fclean: clean
	make -C $(MLX_PATH) clean
	make -C $(LIBFT_PATH) fclean
	${RM} $(NAME)

re: fclean all

.PHONY: all clean fclean re
