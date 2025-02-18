/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:49:54 by lzorzit           #+#    #+#             */
/*   Updated: 2025/02/17 16:33:47 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minilibx/mlx.h"
#include "get_next_line/get_next_line.h"
#include "so_long.h"

int flood (char **mapc,t_flood *vars, int y, int x)
{
	if ( mapc[vars ->line + y][vars -> pos + x] == 'C')
	vars ->got ++;
	if ( mapc[vars ->line + y][vars -> pos + x] == 'E')
		vars ->end ++;
	mapc[vars -> line + y][vars -> pos + x] = '2';
	vars -> change ++;
	return (0);
}

int fill (char **mapc,t_flood *vars)
{
	vars -> change = 0;
	if (mapc[vars ->line][vars ->pos + 1] == '0' || mapc[vars ->line][vars ->pos + 1] == 'C' ||  mapc[vars ->line][vars ->pos + 1] == 'E' )
		flood (mapc, vars, 0, 1);
	if (mapc[vars -> line][vars -> pos - 1] == '0' || mapc[vars ->line][vars -> pos - 1] == 'C' ||  mapc[vars ->line][vars -> pos - 1] == 'E' )
		flood (mapc, vars, 0, -1);
	if (mapc[vars ->line + 1][vars -> pos] == '0' || mapc[vars ->line + 1][vars -> pos] == 'C' ||  mapc[vars ->line + 1][vars -> pos ] == 'E' )
		flood (mapc, vars, 1, 0);
	if (mapc[vars ->line - 1][vars -> pos] == '0' || mapc[vars ->line - 1][vars -> pos] == 'C' ||  mapc[vars ->line - 1][vars -> pos ] == 'E' )
		flood (mapc, vars, -1, 0);
	return (0);
}

int floodfill (char **map, int coll)
{
	t_flood vars;
	vars.got = 0;
	vars.end = 0;
	vars.change = 1;
	vars.line = 1;
	vars.pos = 1;
	while (vars.change != 0)
	{
		vars.change = 0;
		while (map[vars.line] != 0)
		{
			while (map[vars.line][vars.pos] != '\0' )
			{
				if (map[vars.line][vars.pos] == '2' || map[vars.line][vars.pos] == 'P')
					fill(map, &vars);
				vars.pos ++;
			}
			vars.line ++;	
			vars.pos = 1;
		}
		vars.line = 1;
	}
	if (vars.end == 1 && vars.got >= coll)
		return (0);
	return (1);
}

int	isequalsize(char **map, int fdlines,int *size)
{
	int	row;
	
	row = 0;
	size[0] = ft_strlen ( map[row]);
	while (row != (fdlines - 1))
	{
		if (size[0] != ft_strlen( map[row]))
			return (0);
		row ++;
	}
	if (size[0] < 4)
		return(0);
	return (1);
}

int checkline(char *str, int isfirst, t_mapitems *items)
{
	int	pos;

	pos = 0;
	if (isfirst == 1)
	{
		while (str[pos]== '1')
		{
			pos ++;
		}
		if (str[pos] != '\n')
			return (1);
	}
	while (str[pos]!= '\n' && isfirst != 1)
	{
		if ( (pos == 0 || pos == (ft_strlen(str) - 2)) && str[pos]!= '1')
			return (1);
		if ( str[pos] == 'C')
			items->collect ++;
		if ( str[pos] == 'E')
			items->end ++;
		if ( str[pos] == 'P')
			items->start ++;
		pos ++;
	}
	return (0);
}

int	ismapvalid (char **map, int fdlines)
{
	t_mapitems items;
	int	row;
	int	size;

	items.star = 0;
	items.end = 0;
	items.coll = 0;
	row = 0;
	size = 0;
	if (isequalsize(map, fdlines, &size) == 0)
		return (0);
	while (map[row] != 0)
	{
		if (row == 0 || row == (fdlines -2))
			if (checkline ( map[row], 1, &items) == 1)
				return (0);
		if (row != 0 && row != (fdlines -2) && checkline ( map[row], 0, &items.star, &items.end, &items.coll) == 1)
			return (0);
		row ++;
	}
	if (items.star != 1 && items.coll < 1 && items.end != 1)
		return (0);
	if (floodfill (map, items.coll) == 1)
		return (0);
	return (1);
}

