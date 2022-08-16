#ifndef __vec3_h__
#define __vec3_h__
#include <stdio.h>

struct tuple3
{
  double x;
  double y;
  double z;
};

typedef struct tuple3 vec3;
typedef struct tuple3 point3;
typedef struct tuple3 colour;

void vec3_set(double x, double y, double z, vec3 *result);

void vec3_copy(vec3 *v, vec3 *result);

void vec3_add(vec3 *v, vec3 *w, vec3 *result);

void vec3_sub(vec3 *v, vec3 *w, vec3 *result);

void vec3_mul(vec3 *v, vec3 *w, vec3 *result);

void vec3_div(vec3 *v, vec3 *w, vec3 *result);

void vec3_mulscalar(vec3 *v, double t, vec3 *result);

void vec3_divscalar(vec3 *v, double t, vec3 *result);

double vec3_dot(vec3 *v, vec3 *w);

double vec3_len_squared(vec3 *v);

double vec3_len(vec3 *v);

void vec3_unit(vec3 *v, vec3 *result);

void vec3_cross(vec3 *v, vec3 *w, vec3 *result);

void colour_print(FILE *os, colour *c);

#endif
