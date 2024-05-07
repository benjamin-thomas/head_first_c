#include <stdio.h>
#include <string.h>

void print_rev(char *s) {
  // size_t represents the largest uint on the target system
  size_t len = strlen(s);

  char *t = s + len - 1;

  while (t >= s) {
    printf("%c", *t);
    t = t - 1; // pointer arithmetic here
  }
  puts("");
}

int main(void) {
  print_rev("ABCDE");

  return 0;
}
