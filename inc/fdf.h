/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:39:37 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/01/02 16:21:30 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#define BUFFER_SIZE 30

# include "window.h"

typedef struct	s_vars
{
	t_mlx		*mlx;
}				t_vars;

typedef struct	s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
}				t_point;

char	*read_file(char *file_name);
int		init_win(t_mlx *mlx);

#endif