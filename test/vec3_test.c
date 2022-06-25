#include <assert.h>
#include <math.h>
#include "../vec3.h"

void test_vec3_set()
{
  vec3 v;
  vec3_set(2.3, 3.2, -4.5, &v);
  assert(v.x == 2.3);
  assert(v.y == 3.2);
  assert(v.z == -4.5);
}

void test_vec3_add()
{
  vec3 v;
  vec3 w;
  vec3 result;
  vec3_set(3.3, 5.9, -1.1, &v);
  vec3_set(5.5, 9.9, -8.8, &w);

  vec3_add(&v, &w, &result);
  assert(result.x == v.x + w.x);
  assert(result.y == v.y + w.y);
  assert(result.z == v.z + w.z);
}

void test_vec3_sub()
{
  vec3 v;
  vec3 w;
  vec3 result;
  vec3_set(4.7, -9.9, 18.1, &v);
  vec3_set(6.9, 7.7, 3.8, &w);

  vec3_sub(&v, &w, &result);
  assert(result.x == v.x - w.x);
  assert(result.y == v.y - w.y);
  assert(result.z == v.z - w.z);
}

void test_vec3_mul()
{
  vec3 v;
  vec3 w;
  vec3 result;
  vec3_set(5.6, -6.7, 8.1, &v);
  vec3_set(8.9, 6.7, 5.5, &w);

  vec3_mul(&v, &w, &result);
  assert(result.x == v.x * w.x);
  assert(result.y == v.y * w.y);
  assert(result.z == v.z * w.z);
}

void test_vec3_div()
{
  vec3 v;
  vec3 w;
  vec3 result;
  vec3_set(2.2, -4.3, 9.1, &v);
  vec3_set(2.7, 7.6, 2.1, &w);

  vec3_div(&v, &w, &result);
  assert(result.x == v.x / w.x);
  assert(result.y == v.y / w.y);
  assert(result.z == v.z / w.z);
}

void test_vec3_mulscalar()
{
  vec3 v;
  double t = 5.8;
  vec3 result;
  vec3_set(6.6, -4.4, 3.3, &v);

  vec3_mulscalar(&v, t, &result);
  assert(result.x == v.x * t);
  assert(result.y == v.y * t);
  assert(result.z == v.z * t);
}

void test_vec3_divscalar()
{
  vec3 v;
  double t = 6.6;
  vec3 result;
  vec3_set(8.6, 3.1, 1.9, &v);

  vec3_divscalar(&v, t, &result);
  assert(result.x == v.x / t);
  assert(result.y == v.y / t);
  assert(result.z == v.z / t);
}

void test_vec3_dot()
{
  vec3 v, w;
  vec3_set(1.0, 2.0, 3.0, &v);
  vec3_set(-8.1, 4.3, 0.004, &w);
  assert(vec3_dot(&v, &w) == v.x * w.x + v.y * w.y + v.z * w.z);
}

void test_vec3_length_squared()
{
  vec3 v;
  vec3_set(1.0, 2.0, 7.0, &v);
  assert(vec3_length_squared(&v) == v.x * v.x + v.y * v.y + v.z * v.z);
}

void test_vec3_length()
{
  vec3 v;
  vec3_set(1.0, 2.0, 7.0, &v);
  assert(vec3_length(&v) == sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

void test_vec3_unit()
{
  vec3 v, w, r;
  double vlen;
  vec3_set(1.0, 2.0, 7.0, &v);
  vlen = vec3_length(&v);
  vec3_divscalar(&v, vlen, &w);
  vec3_unit(&v, &r);
  assert(r.x == w.x);
  assert(r.y == w.y);
  assert(r.z == w.z);
}

void test_vec3_cross()
{
  vec3 v, w, result;
  vec3_set(1.0, 2.0, 3.0, &v);
  vec3_set(-2.0, 6.0, 11.0, &w);
  vec3_cross(&v, &w, &result);
  assert(result.x == v.y * w.z - v.z * w.y);
  assert(result.y == v.x * w.z - v.z * w.x);
  assert(result.z == v.x * w.y - v.y * w.x);
}

int main()
{
  test_vec3_set();
  test_vec3_add();
  test_vec3_sub();
  test_vec3_mul();
  test_vec3_div();
  test_vec3_mulscalar();
  test_vec3_divscalar();
  test_vec3_dot();
  test_vec3_length_squared();
  test_vec3_length();
  test_vec3_unit();
  test_vec3_cross();

  return 0;
}
