#include <assert.h>
#include <math.h>
#include "../ray.h"

void test_ray_set()
{
    ray r;
    point3 origin;
    vec3 direction;
    vec3_set(1.0, 2.0, 3.0, &origin);
    vec3_set(4.0, 5.0, 6.0, &direction);

    ray_set(&origin, &direction, &r);

    assert(r.origin.x == origin.x);
    assert(r.origin.y == origin.y);
    assert(r.origin.z == origin.z);

    assert(r.direction.x == direction.x);
    assert(r.direction.y == direction.y);
    assert(r.direction.z == direction.z);
}

void test_ray_at()
{
    ray r;
    point3 origin;
    vec3 direction;
    point3 result;
    double t;
    vec3_set(1.0, 2.0, 3.0, &origin);
    vec3_set(4.0, 5.0, 6.0, &direction);

    ray_set(&origin, &direction, &r);
    t = 2.0;
    ray_at(&r, t, &result);

    assert(result.x == origin.x + direction.x * t);
    assert(result.y == origin.y + direction.y * t);
    assert(result.z == origin.z + direction.z * t);
}

int main()
{
    test_ray_set();
    test_ray_at();

    return 0;
}