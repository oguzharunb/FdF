/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_extra_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:55:19 by obastug           #+#    #+#             */
/*   Updated: 2025/01/13 14:51:21 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	x_y_to_point(int x, int y)
{
	unsigned long	point;

	point = (y) + ((unsigned long)x << 32);
	return (point);
}

int	x(unsigned long point)
{
	return (point >> 32);
}

int	y(unsigned long point)
{
	return ((point << 32) >> 32);
}

unsigned int	ft_atoi_hex(char *str)
{
	unsigned int	res;
	int				val;

	res = 0;
	while (*str)
	{
		if (ft_isdigit(*str))
			val = *str - '0';
		else if (*str >= 'a' && *str <= 'f')
			val = *str - 'a' + 10;
		else if (*str >= 'A' && *str <= 'F')
			val = *str - 'A' + 10;
		res = res * 16 + val;
		str++;
	}
	return (res);
}

size_t	ft_ptrarrlen(unsigned long	*arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
