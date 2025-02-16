
#include "libft/libft.h"
#include "minilibx/mlx.h"
#include "get_next_line/get_next_line.h"
#include "so_long.h"
int put_sprite(int pos, int row, void *mlx, void *mlx_win, char spritechar)
{
	int	*	stupid;
	t_data	sprite;

	stupid = (int*)malloc(sizeof(int) * (1));
	*stupid = 0;
	sprite.img = mlx_new_image (mlx, 16, 16);
	sprite.addr = mlx_get_data_addr(sprite.img, &sprite.bits_per_pixel, &sprite.line_length, &sprite.endian);
	if (spritechar == '1')
		sprite.img = mlx_xpm_file_to_image(mlx, "wall.xpm", stupid, stupid);
	if (spritechar == '0')
		sprite.img = mlx_xpm_file_to_image(mlx, "floor.xpm", stupid, stupid);
	if (spritechar == 'E')
		sprite.img = mlx_xpm_file_to_image(mlx, "exit.xpm", stupid, stupid);
	if (spritechar == 'P' || spritechar == 'R')
		sprite.img = mlx_xpm_file_to_image(mlx, "character.xpm", stupid, stupid);
	if (spritechar == 'C')
		sprite.img = mlx_xpm_file_to_image(mlx, "collect.xpm", stupid, stupid);
	mlx_put_image_to_window(mlx, mlx_win, sprite.img, (pos * 16), (row * 16));
	free(stupid);
	return (0);
}

int	printmap(void *mlx, void *mlx_win, char **map,int fdlines)
{
	int	pos;
	int	row;

	pos = 0;
	row = 0;

	while (row != fdlines -1)
	{
		while (pos != ft_strlen(map[row]) -1)
		{
			if (put_sprite(pos, row, mlx, mlx_win, map[row][pos]) == 1)
				return (0);
			pos++;
		}
		pos = 0;
		row++;
	}
	return (1);
}
