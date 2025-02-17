/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:49:54 by lzorzit           #+#    #+#             */
/*   Updated: 2025/02/12 17:17:56 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minilibx/mlx.h"
#include "get_next_line/get_next_line.h"
#include "so_long.h"

int fill (char **mapc,int line, int coll, int *got,int *end, int *change)
{
	change[0] = 0;
	if (mapc[line][coll + 1] == '0' || mapc[line][coll + 1] == 'C' ||  mapc[line][coll + 1] == 'E' )
	{
		if ( mapc[line][coll + 1] == 'C')
			got[0] ++;
		if ( mapc[line][coll + 1] == 'E')
			end[0] ++;
		mapc[line][coll + 1] = '2';
		change[0] ++;
	}
	if (mapc[line][coll - 1] == '0' || mapc[line][coll - 1] == 'C' ||  mapc[line][coll - 1] == 'E' )
	{
		if ( mapc[line][coll - 1] == 'C')
			got[0] ++;
		if ( mapc[line][coll - 1] == 'E')
			end[0] ++;
		mapc[line][coll - 1] = '2';
		change[0] ++;
	}
	if (mapc[line + 1][coll] == '0' || mapc[line + 1][coll] == 'C' ||  mapc[line + 1][coll ] == 'E' )
	{
		if ( mapc[line + 1][coll] == 'C')
			got[0] ++;
		if ( mapc[line + 1][coll] == 'E')
			end[0] ++;
		mapc[line + 1] [coll] = '2';
		change[0] ++;
	}
	if (mapc[line - 1][coll] == '0' || mapc[line - 1][coll] == 'C' ||  mapc[line - 1][coll ] == 'E' )
	{
		if ( mapc[line - 1][coll] == 'C')
			got[0] ++;
		if ( mapc[line - 1][coll] == 'E')
			end[0] ++;
		mapc[line - 1][coll] = '2';
		change[0] ++;
	}
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
					fill(map, vars.line, vars.pos, &vars.got, &vars.end, &vars.change);
				pos ++;
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

int checkline(char *str, int isfirst, int *start, int *end, int *collect)
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
			collect[0] ++;
		if ( str[pos] == 'E')
			end[0] ++;
		if ( str[pos] == 'P')
			start[0] ++;
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
			if (checkline ( map[row], 1, &items.star, &items.end, &items.coll) == 1)
				return (0);
		else if (checkline ( map[row], 0, &items.star, &items.end, &items.coll) == 1)
					return (0);
		row ++;
	}
	if (items.star != 1 && items.coll < 1 && items.end != 1)
		return (0);
	if (floodfill (map, items.coll) == 1)
		return (0);
	return (1);
}

