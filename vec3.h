#ifndef __vec3_h__
#define __vec3_h__

struct vec3
{
    double x;
    double y;
    double z;
};

void vec3_set(double x, double y, double z, struct vec3 *result);

void vec3_add(struct vec3 *v, struct vec3 *w, struct vec3 *result);

void vec3_sub(struct vec3 *v, struct vec3 *w, struct vec3 *result);

void vec3_mul(struct vec3 *v, struct vec3 *w, struct vec3 *result);

void vec3_div(struct vec3 *v, struct vec3 *w, struct vec3 *result);

void vec3_mulscalar(struct vec3 *v, double t, struct vec3 *result);

void vec3_divscalar(struct vec3 *v, double t, struct vec3 *result);

/**
// Here are the functions we need to implement
// double vec3_dot(v, w)
// void vec3_cross(v, w, r)
// double vec3_len_squared(v)
// double vec3_len(v)
// void vec3_unit(v, w)
*/

#endif
