/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:39:32 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/ 01/07 16:46:36 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "window.h"
#include "libft.h"

#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>

//typedef struct	s_vars
//{
//	t_mlx			*mlx;
//	unsigned long	**map;
//	int				height;
//	int				map_x;
//	int				map_y;
//	double			x_coef;
//	double			y_coef;
//	double			distance;
//	int				line_count;
//	int				line_len;
//	int				anchor_x;
//	int				anchor_y;
//	int				bits_per_pixel;
//	int				endian;
//	int				size_line;
//	char			*data_addr;
//}	t_vars;

int render_x(t_vars *vars, int x, int y, int z)
{
	return (int)(((sin(vars->y_coef) * ((x - vars->anchor_x) * vars->distance) + 10 * y * cos(vars->x_coef))) + vars->map_x + (cos(vars->x_coef) * z * vars->height));
}

int render_y(t_vars *vars, int x, int y, int z)
{
	(void)x;
    return (int)(((sin(vars->x_coef) * (y - vars->anchor_y) * vars->distance + 10 * x * cos(vars->y_coef))) + vars->map_y - (cos(vars->y_coef) * z * vars->height));
}

void render_and_put_pixel(t_vars *vars, int x, int y, unsigned long point)
{
	int final_x;
	int final_y;
	int prev_x;
	int	prev_y;

	final_x = render_x(vars, x, y, get_z(point));
	final_y = render_y(vars, x, y, get_z(point));
	if (x > 0)
	{
		prev_x = render_x(vars, x - 1, y, get_z(vars->map[y][x - 1]));
		prev_y = render_y(vars, x - 1, y, get_z(vars->map[y][x - 1]));
		draw_line(vars, x_y_to_point(final_x, final_y), x_y_to_point(prev_x, prev_y), get_color(point));
	}

	if (y > 0) {
		prev_x = render_x(vars, x, y - 1, get_z(vars->map[y - 1][x]));
		prev_y = render_y(vars, x, y - 1, get_z(vars->map[y - 1][x]));
		draw_line(vars, x_y_to_point(final_x, final_y), x_y_to_point(prev_x, prev_y), get_color(point));
	}
	printf("x,y coordinate: %d, %d\n", x, y);
	printf("map coordinate: %d, %d\n", final_x, final_y);
}

void	render_map(t_vars *vars)
{
	int	i;
	int	j;

	printf("distance: %f\n", vars->distance);
	printf("line count: %d\n", vars->line_count);
	printf("line len: %d\n", vars->line_len);
	printf("anchor point: %d %d\n", vars->anchor_x, vars->anchor_y);

	i = 0;
	while(vars->map[i])
	{
		j = 0;
		while (vars->map[i][j] != ULONG_MAX)
		{
			render_and_put_pixel(vars, j, i, vars->map[i][j]);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars->mlx->mlx_ptr, vars->mlx->win_ptr, vars->mlx->image, 0, 0);
}

void	fdf(t_vars *vars)
{
	mlx_key_hook(vars->mlx->win_ptr, key_handler, vars);
	reset_camera(vars);
	render_map(vars);
	mlx_loop(vars->mlx->mlx_ptr);
	free(vars->mlx->mlx_ptr);
}

void	set_map_props(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map[0][i] != ULONG_MAX)
		i++;
	vars->line_len = i;
	vars->anchor_x = i / 2;
	i = 0;
	while (vars->map[i])
		i++;
	vars->line_count = i;
	vars->anchor_y = i / 2;
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_mlx	mlx;
	char 			*map_str;
	
	if (argc != 2)
	{
		write(STDERR_FILENO, "using: fdf <map>\n", 17);
		return (1);
	}
	map_str = read_file(argv[1]);
	if (!map_str)
		return (write(1, "file couldn't read", 18), 1);
	vars.map = map_string_to_arr_2d(map_str);
	if (!vars.map)
		return (write(1, "invalid map", 11), 1);
	set_map_props(&vars);
	vars.mlx = &mlx;
	init_win(&vars);
	fdf(&vars);

	return (1);
}