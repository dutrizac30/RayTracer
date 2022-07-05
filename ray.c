#include "ray.h"

void ray_set(point3 *origin, vec3 *direction, ray *result)
{
    result->origin.x = origin->x;
    result->origin.y = origin->y;
    result->origin.z = origin->z;

    result->direction.x = direction->x;
    result->direction.y = direction->y;
    result->direction.z = direction->z;
}

void ray_at(ray *r, double t, point3 *result)
{
    vec3_mulscalar(&(r->direction), t, result);
    vec3_add(result, &(r->origin), result);
}
