#include <stdio.h>
#include "vec3.h"

int main()
{

  /* Image */
  int i, j;
  const int image_width = 256;
  const int image_height = 256;

  /*Render*/
  printf("P3\n%d %d\n255\n", image_width, image_height);

  for (j = image_height - 1; j >= 0; --j)
  {
    fprintf(stderr, "\rScanlines remaining: %d ", j);
    for (i = 0; i < image_width; ++i)
    {
      double r = (double)i / (image_width - 1);
      double g = (double)j / (image_width - 1);
      double b = 0.25;

      colour c;
      vec3_set(r, g, b, &c);
      colour_print(stdout, &c);
    }
  }

  fprintf(stderr, "\nDone.\n");
  return 0;
}
