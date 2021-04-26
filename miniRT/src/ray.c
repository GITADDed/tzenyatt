#include "ray.h"

void ray_tracing(t_vars *vars, t_scene *scene)
{
	int		mlx_x;
	int		mlx_y;
	double	x_angle;
	double	y_angle;
	int		color;
	double y_ray;
	double x_ray;
	t_vector3d *ray;
	t_vplane *vplane;

	vplane = new_vplane(scene->width, scene->high, scene->cams->fov);
	y_angle = scene->high / 2;
	mlx_y = 0;
	while (y_angle >= scene->high / 2 * -1)
	{
		y_ray = y_angle * vplane->y_pixel;
		x_angle = scene->width / 2 * -1;
		mlx_x = 0;
		while (x_angle <= scene->width / 2)
		{
			x_ray = x_angle * vplane->x_pixel;
			ray = new_vector3d(x_ray, y_ray, -1);
			vec_norm(ray);
			if (intersect(scene->cams, ray, scene->sphere))
 				color = 16777215;
			else
				color = 0;
			mlx_pixel_put(vars->mlx, vars->win, mlx_x, mlx_y, color);
			free(ray);
			x_angle++;
			mlx_x++;
		}
		y_angle--;
		mlx_y++;
	}
	
}