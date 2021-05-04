#include "minirt.h"

void	parser(char **line, t_scene *scene)
{
	scene->line = *line;
	if ((**line) == 'R')
		set_screen(line, scene);
	else if ((**line) == 'A')
		set_ambient_light(line, scene);
	else if ((**line) == 'c' && !ft_isalpha(*((*line) + 1)))
		set_camera(line, scene);
	else if ((**line) == 'l')
		set_light_source(line, scene);
	else if ((**line) == 's' && *((*line) + 1) == 'p')
		set_sphere(line, scene);
	else if ((**line) == 'p' && *((*line) + 1) == 'l')
		set_plane(line, scene);
	else if ((**line) == 's' && *((*line) + 1) == 'q')
		set_square(line, scene);
	else if ((**line) == 't' && *((*line) + 1) == 'r')
		set_triangle(line, scene);
	else if ((**line) == 'c' && *((*line) + 1) == 'y')
		set_cylinder(line, scene);
	else if (!(**line))
		return ;
	else
		map_error("nothing needed found!");
	free (scene->line);
}
