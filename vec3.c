#include <stdio.h>
#include <math.h>
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

void vec3_div(struct vec3 *v, struct vec3 *w, struct vec3 *result)
{
  result->x = v->x / w->x;
  result->y = v->y / w->y;
  result->z = v->z / w->z;
}

void vec3_mulscalar(struct vec3 *v, double t, struct vec3 *result)
{
  result->x = v->x * t;
  result->y = v->y * t;
  result->z = v->z * t;
}

void vec3_divscalar(struct vec3 *v, double t, struct vec3 *result)
{
  result->x = v->x / t;
  result->y = v->y / t;
  result->z = v->z / t;
}

double vec3_dot(struct vec3 *v, struct vec3 *w)
{
  double result = v->x * w->x + v->y * w->y + v->z * w->z;
  return result;
}

double vec3_len_squared(struct vec3 *v)
{
  double result = vec3_dot(v, v);
  return result;
}

double vec3_len(struct vec3 *v)
{
  double result = sqrt(vec3_len_squared(v));
  return result;
}

void vec3_unit(struct vec3 *v, struct vec3 *result)
{
  double len = vec3_len(v);
  vec3_divscalar(v, len, result);
}

void vec3_cross(struct vec3 *v, struct vec3 *w, struct vec3 *result)
{
  result->x = v->y * w->z - v->z * w->y;
  result->y = v->z * w->x - v->x * w->z;
  result->z = v->x * w->y - v->y * w->x;
}