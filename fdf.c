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

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

void	zoom(t_vars *vars, t_point *point)
{
	point->x *= vars->zoom;
	point->y *= vars->zoom;
	point->z *= vars->zoom;
}

void	translate(t_vars *vars, t_point *point)
{
	point->x += vars->map_x;
	point->y -= vars->map_y;
}

void	rotate_z_x(t_vars *vars, t_point *point)
{
	double	original_z;

	original_z = point->z;
	point->z = original_z * cos(vars->z_x_coef) + point->x * -sin(vars->z_x_coef);
	point->x = original_z * sin(vars->z_x_coef) + point->x * cos(vars->z_x_coef);
}

void	rotate_y_z(t_vars *vars, t_point *point)
{
	double	original_y;

	original_y = point->y;
	point->y = point->z * sin(vars->y_z_coef) + original_y * cos(vars->y_z_coef); 
	point->z = point->z * cos(vars->y_z_coef) + original_y * -sin(vars->y_z_coef);
}

void	rotate_x_y(t_vars *vars, t_point *point)
{
	double	original_x;

	original_x = point->x;
	point->x = original_x * cos(vars->x_y_coef) + point->y * -sin(vars->x_y_coef);
	point->y = original_x * sin(vars->x_y_coef) + point->y * cos(vars->x_y_coef);
}

void	render_point(t_vars *vars, t_point *point)
{
	point->x = (point->x - vars->anchor_x) * vars->distance;
	point->y = (point->y - vars->anchor_y) * vars->distance;
	point->z = point->z * vars->height;
	rotate_x_y(vars, point);
	rotate_y_z(vars, point);
	rotate_z_x(vars, point);
	translate(vars, point);
	zoom(vars, point);
}

void	fill_point(t_point *point, int x, int y, int z)
{
	point->x = x;
	point->y = y;
	point->z = z;
}

void render_and_put_pixel(t_vars *vars, int x, int y, unsigned long data)
{
	t_point	left_point;
	t_point	top_point;
	t_point	cur_point;

	fill_point(&cur_point, x, y, get_z(data));
	render_point(vars, &cur_point);
	if (x > 0)
	{
		fill_point(&left_point, x - 1, y, get_z(vars->map[y][x - 1]));
		render_point(vars, &left_point);
		draw_line(vars, x_y_to_point(cur_point.x, cur_point.y), x_y_to_point(left_point.x, left_point.y), get_color(vars->map[y][x - 1]));
	}

	if (y > 0)
	{
		fill_point(&top_point, x, y - 1, get_z(vars->map[y - 1][x]));
		render_point(vars, &top_point);
		draw_line(vars, x_y_to_point(cur_point.x, cur_point.y), x_y_to_point(top_point.x, top_point.y), get_color(vars->map[y - 1][x]));
	}
}

void	render_map(t_vars *vars)
{
	int	i;
	int	j;

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

int	animation_loop(void *v_vars)
{
	t_vars	*vars;

	vars = (t_vars *)v_vars;
	if (vars->animate)
	{
		mlx_clear_window(vars->mlx->mlx_ptr, vars->mlx->win_ptr);
		vars->x_y_coef += 0.01;
		vars->y_z_coef += 0.01;
		vars->z_x_coef += 0.01;
		draw_background(vars);
		render_map(vars);
		usleep(10000);
	}
	return (1);
}

void	fdf(t_vars *vars)
{
	mlx_key_hook(vars->mlx->win_ptr, key_handler, vars);
	mlx_loop_hook(vars->mlx->mlx_ptr, animation_loop, vars);
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