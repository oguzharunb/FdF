/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:09:01 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/01/07 16:42:03 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "window.h"
#include "fdf.h"
#include <stdio.h>

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

void	reset_camera(t_vars *vars)
{
	double	width_distance;
	double	height_distance;

	width_distance = (double)(PADDED_WIDTH) / ((vars->line_len));
	height_distance = (double)(PADDED_HEIGHT) / ((vars->line_count));
	printf("width distance: %lf\n", width_distance);
	printf("height distance: %lf\n", height_distance);
	vars->x_coef = 0;
	vars->y_coef = 0;
	vars->zoom = 1;
	vars->map_x = 0;
	vars->map_y = 0;
	vars->height = 10;
	if (width_distance > height_distance)
		vars->distance = height_distance;
	else
		vars->distance = width_distance;
}

int	close_win(void *param)
{
	t_mlx		*mlx;
	static int	win_exists = 1;

	mlx = (t_mlx *)param;
	if (mlx->win_ptr && win_exists)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx_loop_end(mlx->mlx_ptr);
		win_exists = 0;
		mlx->win_ptr = NULL;
	}
	return (0);
}

#include <unistd.h>
int	key_handler(int keycode, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	if (keycode == ESC_KEY)
	{
		close_win(vars->mlx);
		return (0);
	}
	else if (keycode == W_KEY)
		vars->y_coef += 0.1;
	else if (keycode == S_KEY)
		vars->y_coef -= 0.1;
	else if (keycode == D_KEY)
		vars->x_coef += 0.1;
	else if (keycode == A_KEY)
		vars->x_coef -= 0.1;
	else if (keycode == K_KEY)
		vars->height -= 0.5;
	else if (keycode == J_KEY)
		vars->height += 0.5;
	draw_background(vars);
	render_map(vars);
	return (0);
}

int	init_win(t_vars *vars)
{
	vars->mlx->mlx_ptr = mlx_init();
	if (!vars->mlx->mlx_ptr)
		return (-1);
	vars->mlx->win_ptr = mlx_new_window(vars->mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FdF - obastug");
	if (!vars->mlx->win_ptr)
		return (free(vars->mlx->mlx_ptr), -1);
	vars->mlx->image = mlx_new_image(vars->mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!vars->mlx->image)
		return (close_win(vars->mlx), -1);
	vars->data_addr = mlx_get_data_addr(vars->mlx->image, &vars->bits_per_pixel, &vars->size_line, &vars->endian);
	return (0);
}