#include "minirt.h"

typedef struct s_help
{
	t_list		*obj;
	int			col_det;
	int			flag;
}				t_help;

void	what_is_t(t_help *h, t_scene *scene, t_ray *ray, t_obj_type *type)
{
	if (*type == T_SPHERE)
		h->col_det = sphere_intersection(scene, h->obj->content, ray);
	else if (*type == T_PLANE)
		h->col_det = plane_intersection(scene, h->obj->content, ray);
	else if (*type == T_TRIANGLE)
		h->col_det = triangle_intersection(scene, h->obj->content, ray);
	else if (*type == T_CYLINDER)
		h->col_det = cylinder_intersection(scene, h->obj->content, ray);
	else if (*type == T_SQUARE)
		h->col_det = square_intersection(scene, h->obj->content, ray);
}

int	test_intersection(t_scene *scene, t_ray *ray)
{
	t_hit		tmp;
	t_help		h;

	ft_memset(&tmp, '\0', sizeof(t_hit));
	tmp.t = INFINITY;
	h.obj = scene->objs;
	h.col_det = 0;
	h.flag = 0;
	while (h.obj)
	{
		what_is_t(&h, scene, ray, (t_obj_type *)h.obj->content);
		if (h.col_det && scene->closest.t < tmp.t)
		{
			tmp = scene->closest;
			h.flag = 1;
		}
		h.obj = (h.obj)->next;
	}
	if (h.flag)
	{
		scene->closest = tmp;
		h.col_det = 1;
	}
	return (h.col_det);
}

void	init_normal(t_scene *scene)
{
	t_obj_type	*type;
	void		*obj;

	obj = scene->closest.figure;
	type = scene->closest.figure;
	if (*type == T_SPHERE)
		scene->closest.norm = ((t_sphere *)obj)->vec_n;
	else if (*type == T_TRIANGLE)
		scene->closest.norm = vec_normalisation(((t_triangle *)obj)->vec_n);
	else if (*type == T_SQUARE)
		scene->closest.norm = ((t_square *)obj)->vec_n;
	else if (*type == T_PLANE)
		scene->closest.norm = ((t_plane *)obj)->vec_n;
	else if (*type == T_CYLINDER)
		scene->closest.norm = ((t_cylinder *)obj)->surf_norm;
}

int	get_color(t_hit *hit)
{
	if (hit->type == T_SPHERE)
		return (((t_sphere *)hit->figure)->color);
	if (hit->type == T_PLANE)
		return (((t_plane *)hit->figure)->color);
	if (hit->type == T_TRIANGLE)
		return (((t_triangle *)hit->figure)->color);
	if (hit->type == T_CYLINDER)
		return (((t_cylinder *)hit->figure)->color);
	if (hit->type == T_SQUARE)
		return (((t_square *)hit->figure)->color);
	return (0);
}
