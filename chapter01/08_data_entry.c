#include <stdio.h>

void simple(void) {
  char name[40];
  printf("Enter your name: ");
  scanf("%39s", name); // up to 39 chars + \0

  int age;
  printf("Enter your age: ");
  scanf("%d", &age);

  printf("Hello, %s! You are %d years old :)\n", name, age);
}

void multiple_strings(void) {
  // We can also enter multiple items at a time
  char first_name[20];
  char last_name[20];
  printf("Enter your first name and last name: ");
  scanf("%s %s", first_name, last_name);

  printf("Your full name is: %s %s\n", first_name, last_name);
}

void safer_with_fgets(void) {
  /* If we forget to limit the input length with `scanf`, we run the risk of
   * getting a buffer overflow (we read too far), which may many manifest
   * itself as a `segmentation fault`, or other kind of crashes.
   *
   * For this reason, `fgets` provides a safer alternative.
   */
  char short_code_a[4];
  printf(
      "sizeof(short_code_a) = %ld\n",
      sizeof(short_code_a)); // => 4 (the actual size of the array, i.e. 4 * 1)
  char short_code_b_orig[4];
  char *short_code_b = &short_code_b_orig[0];
  printf("sizeof(short_code_b) = %ld\n",
         sizeof(short_code_b)); // => 8 (the size of the pointer type!)

  printf("Enter short code A+B (max 3+3): ");
  // scanf("%s", short_code); // crashes on input=ABCDE (not ABC surprisingly)
  fgets(short_code_a, sizeof(short_code_a), stdin);
  fgets(short_code_b, 4,
        stdin); // if using a pointer, specify the size manually.

  printf("\nSaving short code >>%s<< and >>%s<<\n", short_code_a, short_code_b);

  // NOTE: `gets` is also available, but dangerous since it doesn't limit the
  // length of the input. Don't use it.
}

int main(void) {
  // simple();
  // multiple_strings();
  safer_with_fgets();
  return 0;
}
