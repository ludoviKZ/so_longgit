/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:10:17 by lzorzit           #+#    #+#             */
/*   Updated: 2025/02/21 19:49:44 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minilibx/mlx.h"
#include "so_long.h"

int		isvalidchar(char i)
{
	if (i != 'E' && i != 'C' && i != 'P' && i != '1' && i != '0')
		return (1);
	return (0);
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

int	filelen(int fd, char *file, int *column)
{
	char	*str;
	int		count;

	count = 1;
	while (count >= 0)
	{
		str = get_next_line(fd);
		if (column[0] == 1)
			column[0] = ft_strlen(str);
		if (!str)
		{
			close (fd);
			fd = open(file, O_RDONLY);
			return (count);
		}
		free (str);
		count ++;
	}
	return (0);
}

int	x_close(t_vars *vars)
{
	closewin(1, vars, "error\nwindowclosed");
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
