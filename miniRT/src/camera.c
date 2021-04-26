#include "camera.h"

t_camera *new_camera(t_vector3d *pos, t_vector3d *dir, double fov)
{
	t_camera *cam;

	cam = malloc(sizeof(t_camera));
	if (cam == NULL)
		return (NULL);
	cam->dir = dir;
	cam->fov = fov;
	cam->pos = pos;
	return (cam);
}