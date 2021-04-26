#ifndef VECTOR_H
# define VECTOR_H

#include <stdlib.h>
#include <math.h>

typedef struct s_vector3d
{
	double x;
	double y;
	double z;
}				t_vector3d;

typedef struct s_vector2d
{
	double x;
	double y;
}				t_vector2d;

t_vector2d *new_vector2d(double x, double y);
t_vector3d *new_vector3d(double x, double y, double z);
t_vector3d *vec_sub(t_vector3d *vec1, t_vector3d *vec2);
double		vec_len(t_vector3d *vec);
void		vec_norm(t_vector3d *vec);
double		dot(t_vector3d *vec1, t_vector3d *vec2);

#endif