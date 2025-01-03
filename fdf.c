/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:39:32 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/01/03 16:55:03 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "window.h"
#include "libft.h"

#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>
unsigned int	ft_atoi_hex(char *str);

int	main()
{
	//t_vars	vars;
	//t_mlx	mlx;
	
	// char	*map = read_file("test_maps/42.fdf");
	// printf("%s", map);
	// free(map);
	//vars.mlx = &mlx;
	//if (init_win(vars.mlx) == -1)
	char 			*map_str = read_file("test_maps/42.fdf");
    unsigned long	**map = map_string_to_arr_2d(map_str);
	write(1, "helloworld", 10);
	size_t	i;
	size_t	j;
	i = 0;
	j = 0;
	while(map[i])
	{
		while (map[i][j] != ULONG_MAX)
		{
			printf("i: %lu, ", i);
			printf("z: %lu, ", map[i][j] >> 32);
			printf("color: %lu\n", map[i][j] & COLOR_MASK);
			j++;
		}
		i++;
	}
	return (1);
}