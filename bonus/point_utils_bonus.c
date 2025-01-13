/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:12:01 by obastug           #+#    #+#             */
/*   Updated: 2025/01/13 14:52:07 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

unsigned long	get_z(unsigned long point)
{
	return (point >> 32);
}

unsigned long	get_color(unsigned long point)
{
	return (point & COLOR_MASK);
}

void	fill_point(t_point *point, int x, int y, int z)
{
	point->x = x;
	point->y = y;
	point->z = z;
}
