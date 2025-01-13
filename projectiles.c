/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:09:58 by obastug           #+#    #+#             */
/*   Updated: 2025/01/13 13:38:46 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pro_parallel(t_vars *vars)
{
	double	width_distance;
	double	height_distance;

	width_distance = (double)(PADDED_WIDTH) / ((vars->line_len));
	height_distance = (double)(PADDED_HEIGHT) / ((vars->line_count));
	vars->x_y_coef = 0;
	vars->y_z_coef = -1;
	vars->z_x_coef = 0.3;
	vars->zoom = 1;
	vars->animate = 0;
	vars->map_x = 0;
	vars->map_y = 0;
	vars->height = 5;
	if (width_distance > height_distance)
		vars->distance = height_distance;
	else
		vars->distance = width_distance;
}

void	pro_top_view(t_vars *vars)
{
	double	width_distance;
	double	height_distance;

	width_distance = (double)(PADDED_WIDTH) / ((vars->line_len));
	height_distance = (double)(PADDED_HEIGHT) / ((vars->line_count));
	vars->x_y_coef = 0;
	vars->y_z_coef = 0;
	vars->z_x_coef = 0;
	vars->zoom = 1;
	vars->animate = 0;
	vars->map_x = 0;
	vars->map_y = 0;
	vars->height = 5;
	if (width_distance > height_distance)
		vars->distance = height_distance;
	else
		vars->distance = width_distance;
}