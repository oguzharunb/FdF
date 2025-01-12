/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:55:29 by obastug           #+#    #+#             */
/*   Updated: 2025/01/12 18:09:43 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "window.h"
#include "libft.h"
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <math.h>

#include <stdio.h>
void	fdf(t_vars *vars)
{
	mlx_key_hook(vars->mlx->win_ptr, key_handler, vars);
	mlx_loop_hook(vars->mlx->mlx_ptr, animation_loop, vars);
	reset_camera(vars);
	render_map(vars);
	printf("yes\n");
	mlx_loop(vars->mlx->mlx_ptr);
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

#include <stdio.h>
int	main(int argc, char **argv)
{
	t_vars	vars;
	t_mlx	mlx;
	char 	*map_str;
	
	if (argc != 2)
	{
		write(STDERR_FILENO, "using: fdf <map>\n", 17);
		return (1);
	}
	map_str = read_file(argv[1]);
	if (!map_str)
		return (write(1, "file couldn't read", 18), 1);
	vars.map = map_string_to_arr_2d(map_str);
	if (!vars.map)
		return (write(1, "invalid map", 11), 1);
	free(map_str);
	set_map_props(&vars);
	vars.mlx = &mlx;
	init_win(&vars);
	fdf(&vars);
	mlx_destroy_image(mlx.mlx_ptr, mlx.image);
	mlx_destroy_window(mlx.mlx_ptr, mlx.win_ptr);
	mlx_destroy_display(mlx.mlx_ptr);
	if (mlx.mlx_ptr)
		free(mlx.mlx_ptr);
	free(vars.map);
	return (0);
}