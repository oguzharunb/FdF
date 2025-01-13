/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_extra_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:55:50 by obastug           #+#    #+#             */
/*   Updated: 2025/01/13 14:51:55 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf_bonus.h"
#include "mlx.h"

void	free_string_list(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	free_number_map(unsigned long **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	destroy_mlx(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->image);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
}
