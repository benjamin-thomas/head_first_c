
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char card_name[3];
  int count = 0;
  do {

    puts("Enter the card_name: ");
    scanf("%2s", card_name); // 2 chars for the name + 1 char for '\0'
    int val = 0;

    switch (card_name[0]) {
    case 'K':
    case 'Q':
    case 'J':
      val = 10;
      break;
    case 'A':
      val = 11;
      break;
    case 'X':
      continue;
    default:
      val = atoi(card_name);
    }

    if (val >= 3 && val <= 6) {
      count++;
    } else if (val == 10) {
      count--;
    }
    printf("Current count: %i\n", count);
  } while (card_name[0] != 'X');
  return 0;
}