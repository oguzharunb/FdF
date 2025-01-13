/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:55:29 by obastug           #+#    #+#             */
/*   Updated: 2025/01/13 15:30:53 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "window.h"
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <math.h>

void	fdf(t_vars *vars)
{
	mlx_key_hook(vars->mlx->win_ptr, key_handler, vars);
	pro_parallel(vars);
	render_map(vars);
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

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_mlx	mlx;
	char	*map_str;

	if (argc != 2)
	{
		write(STDERR_FILENO, "using: fdf <map>\n", 17);
		return (1);
	}
	map_str = read_file(argv[1]);
	if (!map_str)
		return (write(1, "file couldn't read\n", 19), 1);
	vars.map = map_string_to_arr_2d(map_str);
	if (!vars.map)
		return (write(1, "invalid map\n", 12), 1);
	free(map_str);
	set_map_props(&vars);
	vars.mlx = &mlx;
	if (init_win(&vars))
		return (1);
	fdf(&vars);
	destroy_mlx(&mlx);
	free(mlx.mlx_ptr);
	free_number_map(vars.map);
	return (0);
}
