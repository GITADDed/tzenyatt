#ifndef VPLANE_H
# define VPLANE_H

#include "miniRT.h"

typedef struct s_vplane
{
	double width;
	double high;
	double x_pixel;
	double y_pixel;
	double fov;
}				t_vplane;

t_vplane *new_vplane(double width, double high, double fov);

#endif