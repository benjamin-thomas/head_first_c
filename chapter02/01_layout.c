#include <stdio.h>

/*
STACK
--
HEAP
--
GLOBALS
--
CONSTANTS
--
CODE
 */

int y =
    1; // Will be stored in the "globals" section (because outside a function)

int main(void) {
  int x = 4; // Will live on the stack (because inside a function)
  printf("x is stored at %p\n", (void *)&x);
  return 0;
}
