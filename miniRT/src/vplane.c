#include "vplane.h"

t_vplane *new_vplane(double width, double high, double fov)
{
	t_vplane *a;
	double aspect_ratio;

	a = malloc(sizeof(t_vplane));
	if (!a)
		return (NULL);
	a->width = tan(fov / 2 * (M_PI / 180));
	aspect_ratio = width / high;
	a->fov = fov;
	a->high = a->width / aspect_ratio;
	a->x_pixel = a->width / width;
	a->y_pixel = a->high / high;
	return (a);
}