/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:39:32 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/01/02 16:47:26 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "window.h"
#include "libft.h"

#include <stdio.h>
#include <stdlib.h>
int	main()
{
	//t_vars	vars;
	//t_mlx	mlx;
	
	char	*map = read_file("test_maps/42.fdf");
	printf("%s", map);
	free(map);
	//vars.mlx = &mlx;
	//if (init_win(vars.mlx) == -1)
	return (1);
}