/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:09:42 by obastug           #+#    #+#             */
/*   Updated: 2025/01/13 14:35:54 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel(t_vars *vars, int x, int y, int color)
{
	int		i;

	if ((WIN_WIDTH / 2) + x >= 0 && ft_abs((WIN_WIDTH / 2) + x)
		< WIN_WIDTH && (WIN_HEIGHT / 2) + y >= 0 && ft_abs((WIN_HEIGHT / 2))
		+ y < (WIN_HEIGHT))
	{
		i = (((WIN_WIDTH / 2) + x) * vars->bits_per_pixel / 8)
			+ (((WIN_HEIGHT / 2) + y) * vars->size_line);
		vars->data_addr[i] = color;
		vars->data_addr[++i] = color >> 8;
		vars->data_addr[++i] = color >> 16;
	}
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

void	render_and_put_pixel(t_vars *vars, int x, int y, unsigned long data)
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
		draw_line(vars, x_y_to_point(cur_point.x, cur_point.y),
			x_y_to_point(left_point.x, left_point.y),
			get_color(vars->map[y][x - 1]));
	}
	if (y > 0)
	{
		fill_point(&top_point, x, y - 1, get_z(vars->map[y - 1][x]));
		render_point(vars, &top_point);
		draw_line(vars, x_y_to_point(cur_point.x, cur_point.y),
			x_y_to_point(top_point.x, top_point.y),
			get_color(vars->map[y - 1][x]));
	}
}

void	draw_background(t_vars *vars)
{
	int	*back_ground;
	int	i;

	back_ground = (int *)(vars->data_addr);
	i = 0;
	while (i < WIN_HEIGHT * WIN_WIDTH)
	{
		back_ground[i] = 0x0;
		i++;
	}
}
