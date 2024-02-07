#include <stdio.h>

void skip(char *msg) {
  // Prints from the 7th character
  puts(msg + 6);
}

int main(void) {
  char str[] = "abcdefghijklmnopqrstuvwxyz";
  printf("str has length: %ld (+1 is for the NULL char)\n", sizeof(str)); // 27

  puts("---");

  char *str2 = "abcdefghijklmnopqrstuvwxyz";
  printf("An item of a str2 is: %ld bytes (computed from the first item)\n",
         sizeof(str2)); // 8

  puts("---\nMend a broken heart exercise :)");
  char *msg_from_amy = "Don't call me";
  skip(msg_from_amy);

  puts("---");
  puts("Pointer arithmetic");
  int doses[] = {1, 3, 2, 1000};

  /*
  NOTE:

  The array subscript operator is commutative (hence `3[doses]`!).

  That's because array access is syntactic sugar for pointer arithmetic.
  So the expression gets converted to a pointer addition, addition being
  commutative we thus have this surprising way to express things.
  */

  // clang-format off
  printf("3rd array item value: %d == %d == %d == %d\n", *(doses + 3), *(3 + doses), doses[3], 3[doses]);


  // NOTE: a void pointer is known as generic pointer (%p requires it).
  int *a = &doses[3];
  int *b = doses + 3;
  printf("3rd array item address: \n 1)%p\n 2)%p\n 4)%p\n 5)%p\n 6)%p\n 7)%p\n",
    (void *)(doses + 3),
    (void *)(3 + doses),
    (void *)&doses[3],
    (void *)&(3 [doses]),
    (void *)a,
    (void *)b
  );
  // clang-format on

  return 0;
}