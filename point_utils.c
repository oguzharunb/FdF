/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:12:01 by obastug           #+#    #+#             */
/*   Updated: 2025/01/12 17:12:03 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned long	get_z(unsigned long point)
{
	return (point >> 32);
}

unsigned long	get_color(unsigned long point)
{
	return (point & COLOR_MASK);
}
