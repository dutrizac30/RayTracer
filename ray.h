#ifndef __ray_h__
#define __ray_h__
#include "vec3.h"

struct _ray
{
    vec3 direction;
    point3 origin;
};

typedef struct _ray ray;

void ray_set(point3 *origin, vec3 *direction, ray *result);

void ray_at(ray *r, double t, point3 *result);

#endif
