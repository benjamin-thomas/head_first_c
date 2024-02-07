#include <stdio.h>
int main(void) {
  int contestants[] = {1, 2, 3};
  int *choice = contestants;       // [0] points to value: 1
  contestants[0] = 2;              // [0] points to value: 2
  contestants[1] = contestants[2]; // [0] points to value: 2
  contestants[2] = *choice;        // [2] points to value: 2
  printf("I'm going to pick contestant number %i\n", contestants[2]);
  return 0;
}