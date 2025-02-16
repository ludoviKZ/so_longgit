/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:45:37 by lzorzit           #+#    #+#             */
/*   Updated: 2025/02/12 19:41:18 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minilibx/mlx.h"
#include "get_next_line/get_next_line.h"
#include "so_long.h"

int	filelen(int fd)
{
	char	*str;
	int		count;

	count = 1;
	while (count >= 0)
	{
		str = get_next_line(fd);
		if (!str)
		{
			close (fd);
			fd = open("map.txt", O_RDONLY);
			return (count);
		}
		free (str);
		count ++;
	}
	return (0);
}

char **readmap(int fd,int size)
{
	char	**map;
	int		row;
	
	map = (char**)malloc(sizeof(char*) * (size));
	map[size -1] = 0;
	row = 0;
	while (row < (size -1))
	{
		map[row] = get_next_line(fd);
		row ++;
	}
	close (fd);
	fd = open("map.txt", O_RDONLY);
	return(map);
}

int closewin(int keycode, t_vars *vars)
{
	if (keycode == 1)
		mlx_destroy_window(vars -> mlx, vars -> win);
	
	exit(EXIT_SUCCESS);
}
int key_hook(int keycode, t_vars *vars)
{
	if (keycode == 'q')
		closewin(keycode, vars);
	// else if (keycode == W )
	// 	move(vars, 1, 0);
	// else if (keycode == A )
	// 	move(vars, 0, -1);
	// else if (keycode == S )
	// 	move(vars, -1, 0);
	// else if (keycode == D )
	// 	move(vars, 0, +1);
	return (0);
}
int main ()
{
	t_vars	vars;
	t_data	background;
	int		fd;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 400, 400, "gaming");
	background.img = mlx_new_image (vars.mlx, 400, 400);
	background.addr = mlx_get_data_addr(background.img, &background.bits_per_pixel, &background.line_length, &background.endian);
	put_square (&background, 400, 400, 0x0044e4f1);
	mlx_put_image_to_window(vars.mlx, vars.win, background.img, 0, 0);
	fd = open("map.txt", O_RDONLY);
	vars.fdlines = filelen(fd);
	if (vars.fdlines == 1)
		return (0);
	vars.map = readmap(fd, vars.fdlines);
	if (!vars.map)
		return (0);
	if (ismapvalid(vars.map, vars.fdlines) == 0)
		return (0);
	vars.map = readmap(fd, vars.fdlines);
	if (!vars.map)
		return (0);
	if (printmap (vars.mlx, vars.win, vars.map, vars.fdlines) == 0)
	 	return (0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
	free (vars.map);
	return (0);
}
