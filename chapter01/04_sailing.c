#include <stdio.h>

void go_south_east(int *lat, int *lon) {
  *lat -= 1;
  *lon += 1;
}

int main(void) {
  int lat = 32;
  int lon = -64;
  go_south_east(&lat, &lon);

  printf("Avast! Now at: [%i, %i]\n", lat, lon);
  return 0;
}