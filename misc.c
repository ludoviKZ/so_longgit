/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:10:17 by lzorzit           #+#    #+#             */
/*   Updated: 2025/02/19 16:12:08 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minilibx/mlx.h"
#include "get_next_line/get_next_line.h"
#include "so_long.h"

void	fast_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	put_square(t_data *img, int x, int y, int color)
{
	int		sqrx;
	int		sqry;

	sqrx = 0;
	sqry = 0;
	while (sqrx != x)
	{
		while (sqry != y)
		{
			fast_pixel_put (img, sqrx, sqry, color);
			sqry ++;
		}
		sqrx ++;
		sqry = 0;
	}
	return ;
}

void	asignflood(t_flood	*vars)
{
	vars->got = 0;
	vars->end = 0;
	vars->change = 1;
	vars->line = 1;
	vars->pos = 1;
	return ;
}

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

int	isequalsize(char **map, int fdlines, int *size)
{
	int	row;

	row = 0;
	size[0] = ft_strlen (map[row]);
	while (row != (fdlines - 1))
	{
		if (size[0] != ft_strlen(map[row]))
			return (0);
		row ++;
	}
	if (size[0] < 4)
		return (0);
	return (1);
}
