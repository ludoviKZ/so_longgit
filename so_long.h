/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:58:09 by lzorzit           #+#    #+#             */
/*   Updated: 2025/02/24 17:12:58 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# define WALL "wall.xpm"

typedef struct s_coordinate
{
	int	x;
	int	y;
}				t_coordinates;
typedef struct s_flood
{
	int	got;
	int	change;
	int	pos;
	int	line;
	int	end;
}				t_flood;
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;
typedef struct s_mapitems
{
	int	star;
	int	end;
	int	coll;
	int	row;
	int	size;
}				t_mapitems;
typedef struct s_vars
{
	void	*mlx;
	void	*win;
	char	**map;
	int		fdlines;
	int		nmoves;
	int		fd;
	int		column;
}				t_vars;
typedef struct s_sprites
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_sprites;

int		isvalidchar(char i);
int		x_close(t_vars *vars);
void	asignvars(t_vars *vars, char *str);
void	asignflood(t_flood	*vars);
int		filelen(int fd, char *file, int *column);
int		flood(char **mapc, t_flood *vars, int y, int x);
int		iscomplete(t_vars	*vars);
int		move(t_vars	*vars, int ver, int side);
int		movematr(t_vars	*vars, t_coordinates	pos, int ver, int side);
void	put_square(t_data *img, int x, int y, int color);
void	fast_pixel_put(t_data *data, int x, int y, int color);
int		closewin(int keycode, t_vars *vars, char *message);
int		key_hook(int code, t_vars *mlxwin);
int		put_sprite(int x, int y, t_vars	*vars, char spritechar);
int		printmap(t_vars	*vars, char **map, int fdlines);
int		fill(char **map, t_flood *vars);
int		floodfill(char **map, int coll);
int		isequalsize(char **map, int fdlines, int *size);
int		checkline(char *str, int isfirst, t_mapitems *items);
int		ismapvalid(char **map, int fdlines);
void	put_square(t_data *img, int x, int y, int color);
#endif