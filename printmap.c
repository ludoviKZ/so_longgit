
#include "libft/libft.h"
#include "minilibx/mlx.h"
#include "get_next_line/get_next_line.h"
#include "so_long.h"
int put_sprite(int pos, int row, void *mlx, void *mlx_win, char spritechar)
{
	int		stupid;
	int		stupid2;
	t_data	sprite;

	if (spritechar == '1')
		sprite.img = mlx_xpm_file_to_image(mlx, WALL, &stupid, &stupid2);
	else if (spritechar == '0')
		sprite.img = mlx_xpm_file_to_image(mlx, "floor.xpm", &stupid, &stupid2);
	else if (spritechar == 'E')
		sprite.img = mlx_xpm_file_to_image(mlx, "exit.xpm", &stupid, &stupid2);
	else if (spritechar == 'P' || spritechar == 'R')
		sprite.img = mlx_xpm_file_to_image(mlx, "character.xpm", &stupid, &stupid2);
	else if (spritechar == 'C')
		sprite.img = mlx_xpm_file_to_image(mlx, "collect.xpm", &stupid, &stupid2);
	mlx_put_image_to_window(mlx, mlx_win, sprite.img, (pos * 16), (row * 16));
	mlx_destroy_image(mlx, sprite.img);
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
