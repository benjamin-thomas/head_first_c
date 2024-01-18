#include <stdio.h>

void fortune_cookie(char msg[]) {
  printf("Message reads: %s\n", msg);
  printf("msg occupies %li bytes\n", sizeof(msg));
}

int main(void) {
  printf("sizeof(int)   = %li\n", sizeof(int));
  printf("sizeof(\"ABC\") = %li\n", sizeof("ABC"));
  puts("");

  char quote[] = "Cookies make you fat";
  fortune_cookie(quote);
  return 0;
}