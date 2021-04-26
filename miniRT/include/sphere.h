#ifndef SPHERE_H
# define SPHERE_H

#include "vector.h"
#include "camera.h"

typedef struct	s_sphere
{
	double		R;
	t_vector3d	*center;
}				t_sphere;

t_sphere *new_sphere(double R, t_vector3d *center);
int		intersect(t_camera *cam, t_vector3d *ray, t_sphere *sphere);

#endif