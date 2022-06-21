#include <stdio.h>

struct MyStruct
{
  int a;
};

void modifyTheData(struct MyStruct *s)
{
  s->a = 222;
}

void printStruct(struct MyStruct *s)
{
  printf("s->a == %d\n", s->a);
}

int main()
{
  struct MyStruct s;
  printf("Sandbox!\n");
  modifyTheData(&s);
  printStruct(&s);

  return 0;
}
