/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:49:54 by lzorzit           #+#    #+#             */
/*   Updated: 2025/02/24 18:55:45 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfta/libft.h"
#include "minilibx/mlx.h"
#include "so_long.h"

int	flood(char **mapc, t_flood *vars, int y, int x)
{
	if (mapc[vars ->line + y][vars -> pos + x] == 'C')
		vars ->got ++;
	if (mapc[vars ->line + y][vars -> pos + x] == 'E')
		vars ->end ++;
	mapc[vars -> line + y][vars -> pos + x] = '2';
	vars -> change = 1;
	return (0);
}

int	fill(char **mapc, t_flood *vars)
{
	if (mapc[vars ->line][vars ->pos + 1] == '0' || mapc[vars ->line]
		[vars ->pos + 1] == 'C' || mapc[vars ->line][vars ->pos + 1] == 'E' )
		flood (mapc, vars, 0, 1);
	if (mapc[vars -> line][vars -> pos - 1] == '0' || mapc[vars ->line]
		[vars -> pos - 1] == 'C' || mapc[vars ->line][vars -> pos - 1] == 'E' )
		flood (mapc, vars, 0, -1);
	if (mapc[vars ->line + 1][vars -> pos] == '0' || mapc[vars ->line + 1]
		[vars -> pos] == 'C' || mapc[vars ->line + 1][vars -> pos] == 'E' )
		flood (mapc, vars, 1, 0);
	if (mapc[vars ->line - 1][vars -> pos] == '0' || mapc[vars ->line - 1]
		[vars -> pos] == 'C' || mapc[vars ->line - 1][vars -> pos] == 'E' )
		flood (mapc, vars, -1, 0);
	return (0);
}

int	floodfill(char **map, int coll)
{
	t_flood	vars;

	asignflood(&vars);
	while (vars.change == 1)
	{
		vars.change = 0;
		while (map[vars.line] != 0)
		{
			while (map[vars.line][vars.pos] != '\0' )
			{
				if (map[vars.line][vars.pos] == '2' ||
					map[vars.line][vars.pos] == 'P')
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

int	checkline(char *str, int isfirst, t_mapitems *items)
{
	int	pos;

	pos = 0;
	if (isfirst == 1)
	{
		while (str[pos] == '1')
			pos ++;
		if (str[pos] != '\n' && str[pos] != '\0')
			return (1);
	}
	while (str[pos] != '\n' && isfirst != 1)
	{
		if (isvalidchar(str[pos]) == 1)
			return (1);
		if ((pos == 0 || pos == (ft_strlen(str) - 2)) && str[pos] != '1')
			return (1);
		if (str[pos] == 'C')
			items->coll ++;
		if (str[pos] == 'E')
			items->end ++;
		if (str[pos] == 'P')
			items->star ++;
		pos ++;
	}
	return (0);
}

int	ismapvalid(char **map, int fdlines)
{
	t_mapitems		items;
	t_coordinates	pos;

	items.star = 0;
	items.end = 0;
	items.coll = 0;
	pos.y = 0;
	pos.x = 0;
	if (isequalsize(map, fdlines, &pos.x) == 0)
		return (0);
	while (map[pos.y] != 0)
	{
		if (pos.y == 0 || pos.y == (fdlines -2))
			if (checkline (map[pos.y], 1, &items) == 1)
				return (0);
		if (pos.y != 0 && pos.y != (fdlines -2)
			&& checkline(map[pos.y], 0, &items) == 1)
			return (0);
		pos.y ++;
	}
	if (items.star != 1 || items.coll < 1 || items.end != 1)
		return (0);
	if (floodfill (map, items.coll) == 1)
		return (0);
	return (1);
}
