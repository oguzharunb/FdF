/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:56:33 by obastug           #+#    #+#             */
/*   Updated: 2025/01/13 13:39:33 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "window.h"
#include "fdf.h"

int	close_win(void *param)
{
	t_vars		*vars;
	static int	win_exists = 1;

	vars = (t_vars *)param;
	if (win_exists)
	{
		mlx_loop_end(vars->mlx->mlx_ptr);
		win_exists = 0;
	}
	return (0);
}

void	key_handler2(int keycode, t_vars *vars)
{
	if (keycode == E_KEY)
		vars->x_y_coef += 0.1;
	else if (keycode == Q_KEY)
		vars->x_y_coef -= 0.1;
	else if (keycode == W_KEY)
		vars->y_z_coef += 0.1;
	else if (keycode == S_KEY)
		vars->y_z_coef -= 0.1;
	else if (keycode == A_KEY)
		vars->z_x_coef -= 0.1;
	else if (keycode == D_KEY)
		vars->z_x_coef += 0.1;
	else if (keycode == K_KEY)
		vars->height -= 0.5;
	else if (keycode == J_KEY)
		vars->height += 0.5;
	else if (keycode == ARROW_RIGHT_KEY)
		vars->map_x += 5;
	else if (keycode == ARROT_LEFT_KEY)
		vars->map_x -= 5;
	else if (keycode == ARROW_UP_KEY)
		vars->map_y += 5;
	else if (keycode == ARROW_DOWN_KEY)
		vars->map_y -= 5;
}

int	key_handler(int keycode, void *param)
{
	t_vars			*vars;
	static int		once_quit = 0;
	vars = (t_vars *)param;
	if (once_quit)
		return (0);
	if (keycode == ESC_KEY)
	{
		vars->animate = 0;
		once_quit = 1;
		close_win(vars);
		return (0);
	}
	else if (keycode == N_KEY)
		vars->zoom += 0.1;
	else if (keycode == M_KEY && vars->zoom > 0.1)
		vars->zoom -= 0.1;
	else if (keycode == SPACE_KEY)
		vars->animate = !vars->animate;
	else if (keycode == T_KEY)
		pro_top_view(vars);
	else if (keycode == U_KEY)
		pro_parallel(vars);
	key_handler2(keycode, param);
	draw_background(vars);
	render_map(vars);
	return (0);
}

int	init_win(t_vars *vars)
{
	vars->mlx->mlx_ptr = mlx_init();
	if (!vars->mlx->mlx_ptr)
		return (1);
	vars->mlx->win_ptr = mlx_new_window(vars->mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FdF - obastug");
	if (!vars->mlx->win_ptr)
	{
		mlx_destroy_display(vars->mlx->mlx_ptr);
		return (1);
	}
	vars->mlx->image = mlx_new_image(vars->mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!vars->mlx->image)
	{
		mlx_destroy_display(vars->mlx->mlx_ptr);
		mlx_destroy_window(vars->mlx->mlx_ptr, vars->mlx->win_ptr);
		return (1);
	}
	vars->data_addr = mlx_get_data_addr(vars->mlx->image, &vars->bits_per_pixel, &vars->size_line, &vars->endian);
	return (0);
}