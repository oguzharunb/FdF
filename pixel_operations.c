/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:09:42 by obastug           #+#    #+#             */
/*   Updated: 2025/01/12 17:12:07 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel(t_vars *vars, int x, int y, int color)
{
	int		i;

	if ((WIN_WIDTH / 2) + x >= 0 && ft_abs((WIN_WIDTH / 2) + x) < WIN_WIDTH && (WIN_HEIGHT / 2) + y >= 0 && ft_abs((WIN_HEIGHT / 2)) + y < (WIN_HEIGHT))
	{
		i = (((WIN_WIDTH / 2) + x) * vars->bits_per_pixel / 8) + (((WIN_HEIGHT / 2) + y) * vars->size_line);
		vars->data_addr[i] = color;
		vars->data_addr[++i] = color >> 8;
		vars->data_addr[++i] = color >> 16;
	}
}

void	fill_point(t_point *point, int x, int y, int z)
{
	point->x = x;
	point->y = y;
	point->z = z;
}
