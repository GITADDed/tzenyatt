#include "sphere.h"


t_sphere *new_sphere(double R, t_vector3d *center)
{
	t_sphere *fig;

	fig = malloc(sizeof(t_sphere));
	if (fig == NULL)
		return (NULL);
	fig->center = center;
	fig->R = R;
	return (fig);
}

int		intersect(t_camera *cam, t_vector3d *ray, t_sphere *sphere)
{
	double b;
	double c;
	double disc;
	double t1;
	double t2;
	t_vector3d *rd;

	t1 = 0;
	t2 = 0;
	rd = vec_sub(cam->pos, sphere->center);
	b = 2 * dot(rd, ray);
	c = dot(rd, rd) - sphere->R * sphere->R;
	disc = b * b - 4 * c;
	free(rd);
	if (disc < 0.0)
		return(0);
	t1 = ((b * -1) - sqrt(disc)) / 2;
	t2 = ((b * -1) + sqrt(disc)) / 2;
	if (t1 > 0)
		return (1);
	return (0);
}