/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:08:29 by obastug           #+#    #+#             */
/*   Updated: 2025/01/13 12:28:03 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <limits.h>
#include <unistd.h>
#include <mlx.h>

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
		draw_line(vars, x_y_to_point(cur_point.x, cur_point.y)
		, x_y_to_point(left_point.x, left_point.y)
		, get_color(vars->map[y][x - 1]));
	}
	if (y > 0)
	{
		fill_point(&top_point, x, y - 1, get_z(vars->map[y - 1][x]));
		render_point(vars, &top_point);
		draw_line(vars, x_y_to_point(cur_point.x, cur_point.y)
		, x_y_to_point(top_point.x, top_point.y)
		, get_color(vars->map[y - 1][x]));
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
		vars->x_y_coef += 0.005;
		vars->y_z_coef += 0.005;
		vars->z_x_coef += 0.005;
		draw_background(vars);
		render_map(vars);
		usleep(5000);
	}
	return (1);
}
