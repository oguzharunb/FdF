/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:55:15 by obastug           #+#    #+#             */
/*   Updated: 2025/01/13 14:51:32 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include <math.h>

int	ft_abs(int val)
{
	if (val < 0)
		return (-val);
	return (val);
}

void	draw_line(t_vars *vars, unsigned long point1
, unsigned long point2, unsigned long color)
{
	int		steps;
	double	starx;
	double	stary;
	int		i;

	stary = y(point1);
	starx = x(point1);
	steps = ft_abs(y(point2) - y(point1));
	if (ft_abs(x(point2) - x(point1)) > ft_abs(y(point2) - y(point1)))
		steps = ft_abs(x(point2) - x(point1));
	i = 0;
	while (i <= steps)
	{
		ft_put_pixel(vars, (int)(starx), (int)(stary), color);
		starx += (x(point2) - x(point1)) / (double) steps;
		stary += (y(point2) - y(point1)) / (double) steps;
		i++;
	}
}
