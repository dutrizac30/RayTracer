#include <stdio.h>
#include "vec3.h"

void vec3_set(double x, double y, double z, struct vec3 *result)
{
  result->x = x;
  result->y = y;
  result->z = z;
}

void vec3_add(struct vec3 *v, struct vec3 *w, struct vec3 *result)
{
  result->x = v->x + w->x;
  result->y = v->y + w->y;
  result->z = v->z + w->z;
}

void vec3_sub(struct vec3 *v, struct vec3 *w, struct vec3 *result)
{
  result->x = v->x - w->x;
  result->y = v->y - w->y;
  result->z = v->z - w->z;
}

void vec3_mul(struct vec3 *v, struct vec3 *w, struct vec3 *result)
{
  result->x = v->x * w->x;
  result->y = v->y * w->y;
  result->z = v->z * w->z;
}

void vec3_mulscalar(struct vec3 *v, double t, struct vec3 *result)
{
  result->x = v->x * t;
  result->y = v->y * t;
  result->z = v->z * t;
}