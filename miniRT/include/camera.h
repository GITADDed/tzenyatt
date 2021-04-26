#ifndef CAMERA_H
# define CAMERA_H

#include "vector.h"

typedef struct	s_camera
{
	t_vector3d	*pos;
	t_vector3d	*dir;
	double		fov;
}				t_camera;

t_camera *new_camera(t_vector3d *pos, t_vector3d *dir, double fov);

#endif