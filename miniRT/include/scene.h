#ifndef SCENE_H
# define SCENE_H

#include "camera.h"
#include "sphere.h"

typedef struct	s_scene
{
	t_camera	*cams;
	t_sphere	*sphere;
	double		width;
	double		high;
}				t_scene;

t_scene *new_scene(t_camera *cams, t_sphere *sphere, double width, double high);

#endif