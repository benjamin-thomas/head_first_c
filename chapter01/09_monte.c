#include <stdio.h>

/*
This programs will fail at execution time, with a segfault or similar error.

We can't modify the string. Since it's declared as a literal, it is stored in
the "constants" space, so not accessible.

<STACK SPACE>
<HEAP SPACE>
<GLOBALS SPACE>   <-- read only
<CONSTANTS SPACE> <-- read only
<CODE SPACE>      <-- read only
*/

int main() {
  char *cards = "JQK"; // NOTE: prefixing the declaration with `const` wouldn't
                       // be a bad idea when declaring a string literal.

  /*
    To fix this problem, declare and use an array.
    char cards[] = "JQK";

    I think I understand the the string literal will still be stored and the
    constants space, but a copy of it will be made via the array declaration.
  */
  char tmp = cards[1];
  cards[1] = cards[0];
  cards[0] = tmp;

  printf("Cards is now: %s\n", cards);

  return 0;
}