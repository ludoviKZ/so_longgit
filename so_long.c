/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:45:37 by lzorzit           #+#    #+#             */
/*   Updated: 2025/02/16 19:00:24 by lzorzit          ###   ########.fr       */
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
	else if (keycode == 's' )
		move(vars, 1, 0);
	else if (keycode == 'a' )
		move(vars, 0, -1);
	else if (keycode == 'w' )
		move(vars, -1, 0);
	else if (keycode == 'd' )
		move(vars, 0, +1);
	return (0);
}
int main ()
{
	t_vars	vars;
	int		fd;

	vars.nmoves = 0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 400, 400, "gaming");
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
