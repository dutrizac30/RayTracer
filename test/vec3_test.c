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
  vec3 v;
  vec3 w;
  double result;
  vec3_set(4.5, 5.6, 3.3, &v);
  vec3_set(9.1, 7.9, 5.3, &w);

  result = vec3_dot(&v, &w);
  assert(result == v.x * w.x + v.y * w.y + v.z * w.z);
}

void test_vec3_len_squared()
{
  vec3 v;
  double result;
  vec3_set(1.1, 2.2, 3.3, &v);

  result = vec3_len_squared(&v);
  assert(result == vec3_dot(&v, &v));
}

void test_vec3_len()
{
  vec3 v;
  double result;
  vec3_set(8.3, 5.4, -9.9, &v);

  result = vec3_len(&v);
  assert(result == sqrt(vec3_len_squared(&v)));
}

void test_vec3_unit()
{
  vec3 v;
  vec3 tmp;
  double tmp_len;
  vec3 result;
  vec3_set(4.3, 3.3, 6.8, &v);
  vec3_set(4.3, 3.3, 6.8, &tmp);
  tmp_len = vec3_len(&tmp);

  vec3_unit(&v, &result);
  assert(result.x == tmp.x / tmp_len);
  assert(result.y == tmp.y / tmp_len);
  assert(result.z == tmp.z / tmp_len);
}

void test_vec3_cross()
{
  vec3 v;
  vec3 w;
  vec3 result;
  vec3_set(3.8, 1.7, 8.4, &v);
  vec3_set(5.2, -8.5, 7.9, &w);

  vec3_cross(&v, &w, &result);
  assert(result.x == v.y * w.z - v.z * w.y);
  assert(result.y == v.z * w.x - v.x * w.z);
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
  test_vec3_len_squared();
  test_vec3_len();
  test_vec3_unit();
  test_vec3_cross();

  return 0;
}
