#include "vector.h"

t_vector2d *new_vector2d(double x, double y)
{
	t_vector2d *vec;

	vec = malloc(sizeof(t_vector2d));
	if (vec == NULL)
		return (NULL);
	vec->x = x;
	vec->y = y;
	return (vec);
}

t_vector3d *new_vector3d(double x, double y, double z)
{
	t_vector3d *vec;

	vec = malloc(sizeof(t_vector3d));
	if (vec == NULL)
		return (NULL);
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return (vec);
}

t_vector3d *vec_sub(t_vector3d *vec1, t_vector3d *vec2)
{
	return (new_vector3d(vec1->x - vec2->x, vec1->y - vec2->y, vec1->z - vec2->z));
}

double		vec_len(t_vector3d *vec)
{
	return (sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z));
}

void		vec_norm(t_vector3d *vec)
{
	double len;

	len = vec_len(vec);
	vec->x /= len;
	vec->y /= len;
	vec->z /= len;
}

double		dot(t_vector3d *vec1, t_vector3d *vec2)
{
	return (vec1->x * vec2->x + vec1->y *vec2->y + vec1->z * vec2->z);
}