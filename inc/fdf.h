/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:39:37 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/01/03 16:42:07 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#define BUFFER_SIZE 30
#define COLOR_MASK 4294967295U
#define DEFAULT_COLOR 0x00FFFFFF
#include "window.h"
#include <stddef.h>
typedef struct	s_vars
{
	t_mlx		*mlx;
	size_t		line_len;
}				t_vars;

typedef struct	s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
}				t_point;

char			*read_file(char *file_name);
int				init_win(t_mlx *mlx);
unsigned int	ft_atoi_hex(char *str);
unsigned long	point_to_ulong(char *point);
unsigned long	**map_string_to_arr_2d(char *whole_file);
size_t			ft_ptrarrlen(unsigned long	*arr);
#endif