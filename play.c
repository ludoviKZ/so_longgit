/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:22:14 by lzorzit           #+#    #+#             */
/*   Updated: 2025/02/16 19:33:33 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minilibx/mlx.h"
#include "get_next_line/get_next_line.h"
#include "so_long.h"

int	move(t_vars	*vars, int ver, int side)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (vars -> map[y] != 0 && vars -> map[y][x] != 'P'
		&& vars -> map[y][x] != 'R')
	{
		y ++;
		x = 0;
		while (vars -> map[y][x] != '\0' && vars -> map[y][x] != 'P'
			&& vars -> map[y][x] != 'R')
		{
			x ++;
		}
	}
	printf("%c%i%i", vars -> map[y][x], y, x);
	movematr(vars, y, x, ver, side);
	return (0);
}

int	movematr(t_vars	*vars, int y, int x, int ver, int side)
{
	if (vars -> map[y + ver][x + side] == '1')
		return (0);
	else if (vars -> map[y + ver][x + side] == 'E')
	{
		vars -> map[y + ver][x + side] = 'R';
		vars -> map[y][x] = '0';
		if (iscomplete(vars) == 1)
			closewin(1, vars);
	}
	else if (vars -> map[y][x] == 'P')
	{
		vars -> map[y + ver][x + side] = 'P';
		vars -> map[y][x] = '0';
	}
	else if (vars -> map[y][x] == 'R')
	{
		vars -> map[y + ver][x + side] = 'P';
		vars -> map[y][x] = 'E';
	}
	vars -> nmoves ++;
	put_sprite(x, y, vars -> mlx, vars -> win, vars -> map[y][x]);
	put_sprite(x + side, y + ver, vars -> mlx, 
		vars -> win, vars -> map[y + ver][x + side]);
	printf("%i\n%s%s%s", vars -> nmoves, vars -> map[0], vars -> map[1],vars -> map[2]);
	return (0);
}

int	iscomplete(t_vars	*vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < (vars -> fdlines - 1))
	{
		x = 0;
		while (vars -> map[y][x] != '\0')
		{
			if (vars -> map[y][x] == 'C')
				return (0);
			x ++;
		}
		y ++;
	}
	return (1);
}
