#include "fdf.h"
#include <math.h>

#include <stdio.h>
int	ft_abs(int val)
{
	if (val < 0)
		return (-val);
	return (val);
}
void draw_line(t_vars *vars, unsigned long point1, unsigned long point2, unsigned long color)
{
	int dx;
	int dy;
	int steps;
	double starx = x(point1);
	double stary = y(point1);
	
	dx = x(point2) - x(point1);
	dy = y(point2) - y(point1);

	steps = ft_abs(dx) > ft_abs(dy) ? ft_abs(dx) : ft_abs(dy);
	for (int i = 0; i <= steps; i++) {
	    ft_put_pixel(vars, (int)(starx), (int)(stary), color);
	    starx += dx / (double) steps;
	    stary += dy / (double) steps;
	}
}