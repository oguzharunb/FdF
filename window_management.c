/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:56:33 by obastug           #+#    #+#             */
/*   Updated: 2025/01/13 15:04:25 by obastug          ###   ########.fr       */
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
	return (0);
}

int	init_win(t_vars *vars)
{
	vars->mlx->mlx_ptr = mlx_init();
	if (!vars->mlx->mlx_ptr)
		return (1);
	vars->mlx->win_ptr = mlx_new_window(vars->mlx->mlx_ptr, WIN_WIDTH,
			WIN_HEIGHT, "FdF - obastug");
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
	vars->data_addr = mlx_get_data_addr(vars->mlx->image, &vars->bits_per_pixel,
			&vars->size_line, &vars->endian);
	return (0);
}
