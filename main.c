#include <stdio.h>
#include <math.h>
#include "vec3.h"
#include "ray.h"

double hit_sphere(point3 *center, double radius, ray *r)
{
  vec3 oc;
  double a, b, c, discriminant;
  vec3_sub(&(r->origin), center, &oc);
  a = vec3_dot(&(r->direction), &(r->direction));
  b = 2.0 * vec3_dot(&oc, &(r->direction));
  c = vec3_dot(&oc, &oc) - radius * radius;
  discriminant = b * b - 4 * a * c;
  if (discriminant < 0)
  {
    return -1.0;
  }
  else
  {
    return (-b - sqrt(discriminant)) / (2.0 * a);
  }
}

void ray_colour(ray *r, colour *result)
{
  vec3 unit_direction, N;
  double t;
  point3 origin;
  vec3_set(0, 0, -1, &origin);
  t = hit_sphere(&origin, 0.5, r);
  if (t > 0)
  {
    ray_at(r, t, &N);
    vec3_sub(&N, &origin, &N);
    vec3_unit(&N, &N);
    vec3_set(0.5 * (N.x + 1), 0.5 * (N.y + 1), 0.5 * (N.z + 1), result);
  }
  else
  {
    vec3_unit(&(r->direction), &unit_direction);
    t = 0.5 * (unit_direction.y + 1.0);
    vec3_set((1.0 - t) + t * 0.5, (1.0 - t) + t * 0.7, (1.0 - t) + t, result);
  }
}

int main()
{

  int i, j;
  ray r;
  vec3 d;
  colour pixel_colour;

  /*Image*/
  const double aspect_ratio = 16.0 / 9.0;
  const int image_width = 400;
  const int image_height = (int)(image_width / aspect_ratio);

  /*Camera*/
  double viewport_height = 2.0;
  double viewport_width = aspect_ratio * viewport_height;
  double focal_length = 1.0;

  point3 origin;
  vec3 horizontal;
  vec3 vertical;
  point3 lower_left_corner;
  vec3 temp;
  vec3_set(0, 0, 0, &origin);
  vec3_set(viewport_width, 0, 0, &horizontal);
  vec3_set(0, viewport_height, 0, &vertical);
  vec3_set(origin.x, origin.y, origin.z, &lower_left_corner);
  vec3_divscalar(&horizontal, 2, &temp);
  vec3_sub(&lower_left_corner, &temp, &lower_left_corner);
  vec3_divscalar(&vertical, 2, &temp);
  vec3_sub(&lower_left_corner, &temp, &lower_left_corner);
  vec3_set(0, 0, focal_length, &temp);
  vec3_sub(&lower_left_corner, &temp, &lower_left_corner);

  /*Render*/
  printf("P3\n%d %d\n255\n", image_width, image_height);
  for (j = image_height - 1; j >= 0; --j)
  {
    fprintf(stderr, "\rScanlines remaining: %d ", j);
    for (i = 0; i < image_width; ++i)
    {
      double u = (double)(i) / (image_width - 1);
      double v = (double)(j) / (image_height - 1);
      vec3_set(lower_left_corner.x, lower_left_corner.y, lower_left_corner.z, &d);
      vec3_mulscalar(&horizontal, u, &temp);
      vec3_add(&d, &temp, &d);
      vec3_mulscalar(&vertical, v, &temp);
      vec3_add(&d, &temp, &d);
      vec3_sub(&d, &origin, &d);
      ray_set(&origin, &d, &r);

      ray_colour(&r, &pixel_colour);
      colour_print(stdout, &pixel_colour);
    }
  }

  fprintf(stderr, "\nDone.\n");
  return 0;
}
