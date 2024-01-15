/*
echo ./02_code_magnets.c | entr -c bash -c 'gcc ./02_code_magnets.c && ./a.out'
echo ./02_code_magnets.c | entr -c bash -c 'gcc ./02_code_magnets.c && echo OK'
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char card_name[3];
  puts("Enter the card_name: ");
  scanf("%2s", card_name); // 2 chars for the name + 1 char for '\0'
  int val = 0;
  if (card_name[0] == 'K') {
    val = 10;
  } else if (card_name[0] == 'Q') {
    val = 10;
  } else if (card_name[0] == 'J') {
    val = 10;
  } else if (card_name[0] == 'A') {
    val = 11;
  } else {
    // converts text to a number (max=99 given the char[] size contraint)
    val = atoi(card_name);
  }
  printf("The card value is: %i\n", val);
  return 0;
}