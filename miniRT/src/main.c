#include <stdio.h>
#include "miniRT.h"
#include "camera.h"
#include "vplane.h"
#include "sphere.h"
#include "ray.h"
#include "scene.h"
#include "vector.h"

int				close(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(1);
	}
	return (0);
}

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*ds;
	
	ds = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)ds = color;
}


int main(void)
{
	t_data img;
	t_vars vars;
	t_sphere *sphere = new_sphere(12 / 2, new_vector3d(0, 0, -32));
	t_camera *camera = new_camera(new_vector3d(0, 0, 0), new_vector3d(0, 0, -1), 100);
	t_scene *scene = new_scene(camera, sphere, 800, 600);

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 600, "miniRT");
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	img.img = mlx_new_image(vars.mlx, 800, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	&img.endian);
	vars.img = &img;
	ray_tracing(&vars, scene);

	// mlx_put_image_to_window(vars.mlx, vars.win, vars.img->img, 0, 0);
	mlx_loop(vars.mlx);
	return 0;
}
