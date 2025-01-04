/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:09:01 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/01/04 16:36:14 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "window.h"
#include "fdf.h"

void	reset_camera(t_vars *vars)
{
	int width_distance;
	int	height_distance;

	width_distance = (PADDED_WIDTH / 2) / (vars->line_count / 2);
	height_distance = (PADDED_HEIGHT / 2) / (vars->line_len / 2);
	vars->a_coef = 0;
	vars->d_coef = 0;
	vars->d_coef = 0;
	vars->s_coef = 0;
	vars->map_x = 0;
	vars->map_y = 0;
	vars->height = 1;
	if (width_distance > height_distance)
		vars->distance = height_distance;
	else
		vars->distance = width_distance;
}

int	close_win(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx->win_ptr = NULL;
	mlx_loop_end(mlx->mlx_ptr);
	return (0);
}

int	key_handler(int keycode, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	(void)keycode;
	(void)vars;
	if (keycode == ESC_KEY)
	{
		close_win(vars->mlx);
		return (0);
	}
	render_map(vars);
	return (0);
}

int	init_win(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (-1);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FdF!!1!!!1");
	if (!mlx->win_ptr)
		return (free(mlx->mlx_ptr), -1);
	return (0);
}