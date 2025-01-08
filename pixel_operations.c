#include "fdf.h"
//
void	ft_put_pixel(t_vars *vars, int x, int y, int color)
{
	int		i;

	if ((WIN_WIDTH / 2) + x < WIN_WIDTH && (WIN_HEIGHT / 2) + y >= 0 && (WIN_HEIGHT / 2) + y < WIN_HEIGHT)
	{
		i = (((WIN_WIDTH / 2) + x) * vars->bits_per_pixel / 8) + (((WIN_HEIGHT / 2) + y) * vars->size_line);
		vars->data_addr[i] = color;
		vars->data_addr[++i] = color >> 8;
		vars->data_addr[++i] = color >> 16;
	}
}
