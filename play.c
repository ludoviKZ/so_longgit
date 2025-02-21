/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:22:14 by lzorzit           #+#    #+#             */
/*   Updated: 2025/02/21 19:50:55 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minilibx/mlx.h"
#include "so_long.h"

void	asignvars(t_vars *vars, char *str)
{
	vars->nmoves = 0;
	vars->mlx = mlx_init();
	vars->column = 1;
	vars->fd = open(str, O_RDONLY);
	vars->fdlines = filelen(vars->fd, str, &vars -> column);
	vars->win = mlx_new_window(vars->mlx, (vars->column * 16 +1), (vars->fdlines * 16 +1), "gaming");
	return ;
}
int	move(t_vars	*vars, int ver, int side)
{
	t_coordinates	pos;

	pos.x = 0;
	pos.y = 0;
	while (vars -> map[pos.y] != 0 && vars -> map[pos.y][pos.x] != 'P'
		&& vars -> map[pos.y][pos.x] != 'R')
	{
		pos.y ++;
		pos.x = 0;
		while (vars -> map[pos.y][pos.x] != '\0' &&
			vars->map[pos.y][pos.x] != 'P' && vars->map[pos.y][pos.x] != 'R')
		{
			pos.x ++;
		}
	}
	movematr(vars, pos, ver, side);
	return (0);
}

int	movematr(t_vars	*vars, t_coordinates	pos, int ver, int side)
{
	if (vars -> map[pos.y + ver][pos.x + side] == '1')
		return (0);
	else if (vars -> map[pos.y + ver][pos.x + side] == 'E')
	{
		vars -> map[pos.y + ver][pos.x + side] = 'R';
		vars -> map[pos.y][pos.x] = '0';
		if (iscomplete(vars) == 1)
			closewin(1, vars, "you win!");
	}
	else if (vars -> map[pos.y][pos.x] == 'P')
	{
		vars -> map[pos.y + ver][pos.x + side] = 'P';
		vars -> map[pos.y][pos.x] = '0';
	}
	else if (vars -> map[pos.y][pos.x] == 'R')
	{
		vars -> map[pos.y + ver][pos.x + side] = 'P';
		vars -> map[pos.y][pos.x] = 'E';
	}
	vars -> nmoves ++;
	put_sprite(pos.x, pos.y, vars, vars -> map[pos.y][pos.x]);
	put_sprite(pos.x + side, pos.y + ver, vars,
		vars -> map[pos.y + ver][pos.x + side]);
	ft_printf("%i\n", vars -> nmoves);
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
