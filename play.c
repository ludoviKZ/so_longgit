
#include "libft/libft.h"
#include "minilibx/mlx.h"
#include "get_next_line/get_next_line.h"
#include "so_long.h"


int move(t_vars	vars,int ver,int side)
{
	int x;
	int	y;

	x = 0;
	y = 0;
	while (vars.map[y] != 0 && vars.map[y][x] != 'P' && vars.map[y][x] == 'R')
		{
			y ++;	
			x = 0;
			while (vars.map[y][x] != '\0' && vars.map[y][x] != 'P' && vars.map[y][x] == 'R')
			{
				x ++;
			}
		}
	movematr(vars, y, x, ver, side);
}
int movematr(t_vars	vars,int y,int x,int ver,int side)
{
	if (vars.map[y + ver][x + side] == '1')
		return (0);
	else if (vars.map[y + ver][x + side] = 'E')
	{
		vars.map[y + ver][x + side] = 'R';
		vars.map[y][x] = '0';
	}
	else if (vars.map[y][x] == 'P')
	{
		vars.map[y + ver][x + side] = 'P';
		vars.map[y][x] = '0';
	}
	else if (vars.map[y][x] == 'R')
	{
		vars.map[y + ver][x + side] = 'P';
		vars.map[y][x] = 'E';
	}
	return(0);
}