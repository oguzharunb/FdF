/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:02:07 by obastug           #+#    #+#             */
/*   Updated: 2025/01/13 15:49:40 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# define BUFFER_SIZE 50000
# define COLOR_MASK 4294967295U
# define DEFAULT_COLOR 0x00FFFFFF

# include "window_bonus.h"
# include <stddef.h>

typedef struct s_vars
{
	t_mlx			*mlx;
	unsigned long	**map;
	double			height;
	int				animate;
	int				map_x;
	int				map_y;
	double			x_y_coef;
	double			y_z_coef;
	double			z_x_coef;
	double			zoom;
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

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

void			free_string_list(char **map);
void			free_number_map(unsigned long **map);
char			*read_file(char *file_name);
int				init_win(t_vars *vars);
unsigned int	ft_atoi_hex(char *str);
unsigned long	point_to_ulong(char *point);
unsigned long	**map_string_to_arr_2d(char *whole_file);
size_t			ft_ptrarrlen(unsigned long	*arr);

unsigned long	get_color(unsigned long point);
unsigned long	get_z(unsigned long point);

void			render_map(t_vars *vars);
void			destroy_mlx(t_mlx *mlx);

int				key_handler(int keycode, void *param);
int				close_win(void *param);
void			pro_top_view(t_vars *vars);
void			pro_parallel(t_vars *vars);
void			pro_conic_view(t_vars *vars);

void			render_and_put_pixel(t_vars *vars, int x,
					int y, unsigned long data);
int				animation_loop(void *v_vars);
void			ft_put_pixel(t_vars *vars, int x,
					int y, int color);
void			draw_line(t_vars *vars, unsigned long point1,
					unsigned long point2, unsigned long color);
void			draw_background(t_vars *vars);
int				ft_abs(int val);
int				x(unsigned long point);
int				y(unsigned long point);
unsigned long	x_y_to_point(int x, int y);
void			fill_point(t_point *point, int x, int y, int z);

void			zoom(t_vars *vars, t_point *point);
void			translate(t_vars *vars, t_point *point);
void			rotate_z_x(t_vars *vars, t_point *point);
void			rotate_y_z(t_vars *vars, t_point *point);
void			rotate_x_y(t_vars *vars, t_point *point);
#endif