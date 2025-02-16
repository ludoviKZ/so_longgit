/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:58:09 by lzorzit           #+#    #+#             */
/*   Updated: 2025/02/12 18:02:26 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#ifndef SO_LONG_H
# define SO_LONG_H

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;
typedef struct	s_mapitems {
	int	start;
	int	end;
	int coll;
	int row;
	int	size;
}				t_mapitems;
typedef struct	s_vars {
	void	*mlx;
	void	*win;
	char	**map;
	int		fdlines;
}				t_vars;
typedef struct	s_sprites {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_sprites;

void	put_square(t_data *img,int x,int y, int color);
void	fast_pixel_put(t_data *data, int x, int y, int color);
int	closewin(int keycode, t_vars *vars);
int 	key_hook(int code, t_vars *mlxwin);
int put_sprite(int pos, int row, void *mlx, void *mlx_win, char spritechar);
int	printmap(void *mlx, void *mlx_win, char **map,int fdlines);
int fill (char **map,int line, int coll, int *got,int *end, int *change);
int floodfill (char **map, int coll);
int	isequalsize(char **map, int fdlines, int *size);
int checkline(char *str, int isfirst, int *start, int *end, int *collect);
int	ismapvalid (char **map, int fdlines);
void	put_square(t_data *img,int x,int y, int color);
#endif