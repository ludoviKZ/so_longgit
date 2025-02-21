/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:45:37 by lzorzit           #+#    #+#             */
/*   Updated: 2025/02/21 17:41:20 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minilibx/mlx.h"
#include "so_long.h"

char	**readmap(int fd, int size, char *file)
{
	char	**map;
	int		row;

	map = (char **)malloc (sizeof(char *) * (size));
	map[size -1] = 0;
	row = 0;
	while (row < (size))
	{
		map[row] = get_next_line(fd);
		row ++;
	}
	close (fd);
	fd = open(file, O_RDONLY);
	return (map);
}

void	free_matrix(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map[i])
		i++;
	while (i > 0)
	{
		i --;
		if (vars->map[i])
			free(vars->map[i]);
	}
	free(vars->map);
}

int	closewin(int keycode, t_vars *vars, char *message)
{
	int	clear;

	clear = 0;
	mlx_destroy_window(vars -> mlx, vars -> win);
	mlx_destroy_display(vars -> mlx);
	ft_printf("%s", message);
	if (keycode == 1)
		free_matrix(vars);
	free (vars -> mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307 || keycode == 'q')
		closewin(1, vars, "error\nforcequit");
	else if (keycode == 's' )
		move(vars, 1, 0);
	else if (keycode == 'a' )
		move(vars, 0, -1);
	else if (keycode == 'w' )
		move(vars, -1, 0);
	else if (keycode == 'd' )
		move(vars, 0, +1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc == 2 && ft_strnstr(argv[1],".ber",ft_strlen(argv[1])) != 0)
		asignvars(&vars, argv[1]);
	else
		return (ft_printf("error\nno arg/invalid arg"), 0);
	if (vars.fdlines < 4 || vars.fdlines > 51)
		return (closewin(0, &vars, "error\nmap too big/small"));
	vars.map = readmap(vars.fd, vars.fdlines, argv[1]);
	if (!vars.map)
		return (closewin(0, &vars, "error\nfailed to read map"));
	if (ismapvalid(vars.map, vars.fdlines) == 0)
		return (closewin(1, &vars, "error\nmap invalid"));
	free_matrix(&vars);
	vars.map = readmap(vars.fd, vars.fdlines, argv[1]);
	if (!vars.map)
		return (closewin(0, &vars, "error\nfailed to read map"));
	if (printmap (&vars, vars.map, vars.fdlines) == 0)
		return (closewin(1, &vars, "error\nfailed to print map"));
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 1L << 2, x_close, &vars);
	mlx_loop(vars.mlx);
	free_matrix(&vars);
	return (closewin(0, &vars, "error\nuknown error, end of program"));
}
