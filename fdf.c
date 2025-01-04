/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:39:32 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/01/04 16:36:54 by obastug          ###   ########.fr       */
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


void	put_pixel(void *mlx_ptr, void *win_ptr, int x, int y, unsigned long color)
{
	printf("pixel sent to mlx: %d, %d\n", (WIN_WIDTH / 2) + x, (WIN_HEIGHT / 2) - y);
	mlx_pixel_put(mlx_ptr, win_ptr, (WIN_WIDTH / 2) + x, (WIN_HEIGHT / 2) + y, color);
}

void	render_and_put_pixel(t_vars *vars, int x, int y, unsigned long point)
{
	int final_x;
	int	final_y;

	final_x = (x - vars->anchor_x) * vars->distance;
	final_y = (y - vars->anchor_y) * vars->distance;
	put_pixel(vars->mlx->mlx_ptr, vars->mlx->win_ptr, final_x, final_y, get_color(point));
	printf("anchor point: %d %d\n", vars->anchor_x, vars->anchor_y);
	printf("coordinate: %d, %d\n", final_x, final_y);
	printf("distance: %d\n", vars->distance);
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
			render_and_put_pixel(vars, i, j, vars->map[i][j]);
			j++;
		}
		i++;
	}
}

void	fdf(t_vars *vars)
{
	// mlx_hook(vars->mlx->mlx_ptr, ON_DESTROY, 0, close_win, vars->mlx);
	reset_camera(vars);
	mlx_key_hook(vars->mlx->win_ptr, key_handler, vars);
	mlx_loop(vars->mlx->mlx_ptr);
	mlx_destroy_display(vars->mlx->mlx_ptr);
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

int	main()
{
	t_vars	vars;
	t_mlx	mlx;
	char 			*map_str;
	
	map_str = read_file("test_maps/2x2.fdf");
	if (!map_str)
		return (write(1, "file couldn't read", 18), 1);
	vars.map = map_string_to_arr_2d(map_str);
	if (!vars.map)
		return (write(1, "invalid map", 11), 1);
	set_map_props(&vars);
	vars.mlx = &mlx;
	init_win(&mlx);
	fdf(&vars);

	return (1);
}