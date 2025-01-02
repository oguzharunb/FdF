/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:09:01 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/01/02 15:37:30 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "window.h"

static int	close_win(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx->win_ptr = NULL;
	mlx_loop_end(mlx->mlx_ptr);
	return (0);
}

static int	esc_handler(int keycode, void *param)
{
	if (keycode == ESC_KEY)
		close_win(param);
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
	mlx_hook(mlx->win_ptr, ON_DESTROY, 0, close_win, mlx);
	mlx_key_hook(mlx->win_ptr, esc_handler, mlx);
	mlx_loop(mlx->mlx_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	return (0);
}