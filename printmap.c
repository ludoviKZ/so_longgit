
#include "libft/libft.h"
#include "minilibx/mlx.h"
#include "get_next_line/get_next_line.h"
#include "so_long.h"
int put_sprite(int x, int y,t_vars	*vars, char spritechar)
{
	int		stupid;
	int		stupid2;
	t_data	sprite;

	if (spritechar == '1')
		sprite.img = mlx_xpm_file_to_image(vars->mlx, WALL, &stupid, &stupid2);
	else if (spritechar == '0')
		sprite.img = mlx_xpm_file_to_image(vars->mlx, "floor.xpm", &stupid, &stupid2);
	else if (spritechar == 'E')
		sprite.img = mlx_xpm_file_to_image(vars->mlx, "exit.xpm", &stupid, &stupid2);
	else if (spritechar == 'P' || spritechar == 'R')
		sprite.img = mlx_xpm_file_to_image(vars->mlx, "character.xpm", &stupid, &stupid2);
	else if (spritechar == 'C')
		sprite.img = mlx_xpm_file_to_image(vars->mlx, "collect.xpm", &stupid, &stupid2);
	mlx_put_image_to_window(vars->mlx, vars->win, sprite.img, (x * 16), (y * 16));
	mlx_destroy_image(vars->mlx, sprite.img);
	return (0);
}

int	printmap(t_vars	*vars, char **map, int fdlines)
{
	t_coordinates	pos;

	pos.x = 0;
	pos.y = 0;

	while (pos.y != fdlines -1)
	{
		while (pos.x != ft_strlen(map[pos.y]) -1)
		{
			if (put_sprite(pos.x, pos.y, vars, map[pos.y][pos.x]) == 1)
				return (0);
			pos.x++;
		}
		pos.x = 0;
		pos.y++;
	}
	return (1);
}
