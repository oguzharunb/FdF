/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:08:29 by obastug           #+#    #+#             */
/*   Updated: 2025/01/13 13:38:39 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <limits.h>
#include <unistd.h>
#include <mlx.h>



void	put_info(t_vars *vars)
{
	mlx_string_put(vars->mlx->mlx_ptr, vars->mlx->win_ptr
	, 50, 70, 0xFFFFFF, "Parallel View: U");
	mlx_string_put(vars->mlx->mlx_ptr, vars->mlx->win_ptr
	, 50, 90, 0xFFFFFF, "Top View: T");
	mlx_string_put(vars->mlx->mlx_ptr, vars->mlx->win_ptr
	, 50, 110, 0xFFFFFF, "Translate: Arrow Keys");
	mlx_string_put(vars->mlx->mlx_ptr, vars->mlx->win_ptr
	, 50, 130, 0xFFFFFF, "Rotate x/y: Q-E");
	mlx_string_put(vars->mlx->mlx_ptr, vars->mlx->win_ptr
	, 50, 150, 0xFFFFFF, "Rotate x/z: A-D");
	mlx_string_put(vars->mlx->mlx_ptr, vars->mlx->win_ptr
	, 50, 170, 0xFFFFFF, "Rotate y/z: W-S");
	mlx_string_put(vars->mlx->mlx_ptr, vars->mlx->win_ptr
	, 50, 190, 0xFFFFFF, "Zoom in out: N-M");
	mlx_string_put(vars->mlx->mlx_ptr, vars->mlx->win_ptr
	, 50, 210, 0xFFFFFF, "Height + -: J-K");
	mlx_string_put(vars->mlx->mlx_ptr, vars->mlx->win_ptr
	, 50, 230, 0xFFFFFF, "Animate: Space");
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
	put_info(vars);
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
