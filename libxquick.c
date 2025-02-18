#include "libft/libft.h"
#include "minilibx/mlx.h"
#include "get_next_line/get_next_line.h"
#include "so_long.h"
void	fast_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
void	put_square(t_data *img,int x,int y, int color)
{
	int		sqrx;
	int		sqry;

	sqrx = 0;
	sqry = 0;
	while (sqrx != x)
	{
		while (sqry != y)
		{
			fast_pixel_put ( img, sqrx, sqry, color);
			sqry ++;
		}	
		sqrx ++;
		sqry = 0;
	}
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