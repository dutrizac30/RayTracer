#include <stdio.h>
#include "vec3.h"

void vec3_set(double x, double y, double z, vec3 *result)
{
  result->x = x;
  result->y = y;
  result->z = z;
}

void vec3_add(vec3 *v, vec3 *w, vec3 *result)
{
  result->x = v->x + w->x;
  result->y = v->y + w->y;
  result->z = v->z + w->z;
}

void vec3_sub(vec3 *v, vec3 *w, vec3 *result)
{
  result->x = v->x - w->x;
  result->y = v->y - w->y;
  result->z = v->z - w->z;
}

void vec3_mul(vec3 *v, vec3 *w, vec3 *result)
{
  result->x = v->x * w->x;
  result->y = v->y * w->y;
  result->z = v->z * w->z;
}

void vec3_div(vec3 *v, vec3 *w, vec3 *result)
{
  result->x = v->x / w->x;
  result->y = v->y / w->y;
  result->z = v->z / w->z;
}

void vec3_mulscalar(vec3 *v, double t, vec3 *result)
{
  result->x = v->x * t;
  result->y = v->y * t;
  result->z = v->z * t;
}

void vec3_divscalar(vec3 *v, double t, vec3 *result)
{
  result->x = v->x / t;
  result->y = v->y / t;
  result->z = v->z / t;
}
