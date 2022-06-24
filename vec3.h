#ifndef __vec3_h__
#define __vec3_h__

struct tuple3
{
  double x;
  double y;
  double z;
};
typedef struct tuple3 vec3;
typedef struct tuple3 color;
typedef struct tuple3 point;

void vec3_set(double x, double y, double z, vec3 *result);

void vec3_add(vec3 *v, vec3 *w, vec3 *result);

void vec3_sub(vec3 *v, vec3 *w, vec3 *result);

void vec3_mul(vec3 *v, vec3 *w, vec3 *result);

void vec3_div(vec3 *v, vec3 *w, vec3 *result);

void vec3_mulscalar(vec3 *v, double t, vec3 *result);

void vec3_divscalar(vec3 *v, double t, vec3 *result);

/**
// Here are the functions we need to implement
// double vec3_dot(v, w) == v.x * w.x + v.y * w.y + v.z * w.z
// double vec3_len_squared(v) == vec3_dot(v, v)
// double vec3_len(v) == sqrt(vec3_len_squared(v))
// void vec3_unit(v, r) { vec3_divscalar(v, vec3_len(v), r) }
//
// void vec3_cross(v, w, r) // a bit trickier
*/

#endif
