#include <assert.h>
#include "../vec3.h"

void test_vec3_set()
{
  struct vec3 v;
  vec3_set(2.3, 3.2, -4.5, &v);
  assert(v.x == 2.3);
  assert(v.y == 3.2);
  assert(v.z == -4.5);
}

void test_vec3_add()
{
  struct vec3 v;
  struct vec3 w;
  struct vec3 result;
  vec3_set(3.3, 5.9, -1.1, &v);
  vec3_set(5.5, 9.9, -8.8, &w);

  vec3_add(&v, &w, &result);
  assert(result.x == v.x + w.x);
  assert(result.y == v.y + w.y);
  assert(result.z == v.z + w.z);
}

void test_vec3_sub()
{
  struct vec3 v;
  struct vec3 w;
  struct vec3 result;
  vec3_set(4.7, -9.9, 18.1, &v);
  vec3_set(6.9, 7.7, 3.8, &w);

  vec3_sub(&v, &w, &result);
  assert(result.x == v.x - w.x);
  assert(result.y == v.y - w.y);
  assert(result.z == v.z - w.z);
}

void test_vec3_mul()
{
  struct vec3 v;
  struct vec3 w;
  struct vec3 result;
  vec3_set(5.6, -6.7, 8.1, &v);
  vec3_set(8.9, 6.7, 5.5, &w);

  vec3_mul(&v, &w, &result);
  assert(result.x == v.x * w.x);
  assert(result.y == v.y * w.y);
  assert(result.z == v.z * w.z);
}

void test_vec3_mulscalar()
{
  struct vec3 v;
  double t = 5.8;
  struct vec3 result;
  vec3_set(6.6, -4.4, 3.3, &v);

  vec3_mulscalar(&v, t, &result);
  assert(result.x == v.x * t);
  assert(result.y == v.y * t);
  assert(result.z == v.z * t);
}

int main()
{
  test_vec3_set();
  test_vec3_add();
  test_vec3_sub();
  test_vec3_mul();
  test_vec3_mulscalar();

  return 0;
}
