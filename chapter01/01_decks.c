#include <stdio.h>

/*
  echo ./01_decks.c | entr -c bash -c 'gcc ./01_decks.c && ./a.out'
*/
int main(void) {
  int decks;
  puts("Enter a number of decks");
  scanf("%i", &decks);
  if (decks < 1) {
    puts("That is not a valid number of decks");
    return 1;
  }
  printf("There are %i cards\n", (decks * 42));
  return 0;
}