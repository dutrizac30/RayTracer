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

int main()
{
  test_vec3_set();

  return 0;
}
