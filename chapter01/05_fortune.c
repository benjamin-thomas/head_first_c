#include <stdio.h>

void fortune_cookie(char msg[]) {
  printf("Message reads: %s\n", msg);

  // Gets the size of the pointer value to msg, i.e. msg[0]
  // Thats 8 bytes = 64 bits, because the pointer value is stored as a `long`.
  printf("msg occupies %li bytes (as a `long`, at address: %p==%p)\n",
         sizeof(msg), msg, &msg[0]);
  printf("sizeof(long) = %li\n", sizeof(long));
}

int main(void) {
  printf("sizeof(int)   = %li\n", sizeof(int));
  printf("sizeof(\"ABC\") = %li\n", sizeof("ABC"));
  puts("");

  char quote[] = "Cookies make you fat";
  fortune_cookie(quote);
  return 0;
}