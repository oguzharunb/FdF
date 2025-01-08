/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:39:37 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/01/07 12:47:31 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#define BUFFER_SIZE 50000
#define COLOR_MASK 4294967295U
#define DEFAULT_COLOR 0x00FFFFFF

#include "window.h"
#include <stddef.h>


typedef struct	s_vars
{
	t_mlx			*mlx;
	unsigned long	**map;
	int				height;
	int				map_x;
	int				map_y;
	int				w_coef;
	int				s_coef;
	int				a_coef;
	int				d_coef;
	double			distance;
	int				line_count;
	int				line_len;
	int				anchor_x;
	int				anchor_y;
	int				bits_per_pixel;
	int				endian;
	int				size_line;
	char			*data_addr;

}	t_vars;

char			*read_file(char *file_name);
int				init_win(t_vars *vars);
unsigned int	ft_atoi_hex(char *str);
unsigned long	point_to_ulong(char *point);
unsigned long	**map_string_to_arr_2d(char *whole_file);
size_t			ft_ptrarrlen(unsigned long	*arr);

unsigned long	get_color(unsigned long);
unsigned long	get_z(unsigned long point);

void			render_map(t_vars *vars);

int				key_handler(int keycode, void *param);
int				close_win(void *param);
void			reset_camera(t_vars *vars);

void			ft_put_pixel(t_vars *vars, int x, int y, int color);
void			draw_line(t_vars *vars, unsigned long point1, unsigned long point2, unsigned long color);

int				x(unsigned long point);
int				y(unsigned long point);
unsigned long	x_y_to_point(int x, int y);
#endif