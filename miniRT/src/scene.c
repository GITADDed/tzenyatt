#include "scene.h"

t_scene *new_scene(t_camera *cams, t_sphere *sphere, double width, double high)
{
	t_scene *scene;

	scene = malloc(sizeof(t_scene));
	if (scene == NULL)
		return (NULL);
	scene->cams = cams;
	scene->sphere = sphere;
	scene->high = high;
	scene->width = width;
	return (scene);
}