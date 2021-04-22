#ifndef MINIRT_H
#define MINIRT_H

typedef int boolean;

#define true 1
#define false 0

typedef double Float;

#define EPSILON 1e-5

#define FLOAT_MAX DBL_MAX

#include "color.h"

typedef struct
{
    Float x;
    Float y;
} Point2D;

typedef struct
{
    Float x;
    Float y;
    Float z;
} Point3D;

typedef struct
{
    Float x;
    Float y;
    Float z;
} Vector3D;

typedef struct
{
    void *data;
    boolean (*intersect)(const void *data,
                    const Point3D ray_start_point,
                    const Vector3D ray,
                    Point3D * const intersection_point);
    Color (*get_color)(const void *data, const Point3D intersection_point);
    Vector3D (*get_normal_vector)(const void *data, const Point3D intersection_point);
    void (*realese_data)(void *data);
} Object3D;


#endif