
#include <stdio.h>

// Passing a string to a function
void fortune_cookie(char msg[]) {
  printf("Message reads: %s\n", msg);
  printf("The quote is stored at %p\n", (void *)msg);

  // 8 bytes: the size of the pointer (the type cast satisfies the linters)
  printf("msg occupies %ld bytes\n", sizeof((char *)msg));
  printf("msg occupies %lu bytes\n", sizeof((void *)msg));
}

int main(void) {
  char quote[] = "Cookies make you fat.";
  fortune_cookie(quote);
  return 0;
}
