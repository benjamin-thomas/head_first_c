#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_TRACK_LENGTH 80

char TRACKS[][80] = {
    "I left my heart in Harvard Med School",
    "Newark, Newark - a wonderful town",
    "Dancing with a dork",
    "From here to maternity",
    "The girl from Iwo",
};

void ask_user(char *search_term) {
  printf("Which track do you want to look for? ");
  fgets(search_term, MAX_TRACK_LENGTH, stdin);
  search_term[strlen(search_term) - 1] = '\0'; // chomp
  for (unsigned int i = 0; i < strlen(search_term); i++) {
    search_term[i] = tolower(search_term[i]);
  }
}

int search(char search_term[]) {
  for (unsigned int i = 0; i < sizeof(TRACKS) / sizeof(TRACKS[0]); i++) {
    char curr[MAX_TRACK_LENGTH];
    // NOTE: `strncpy_s` is not supported by gcc.
    strncpy(curr, TRACKS[i], MAX_TRACK_LENGTH); // NOLINT
    for (unsigned int j = 0; j < strlen(curr); j++) {
      curr[j] = tolower(curr[j]);
    }

    if (strstr(curr, search_term)) {
      return i;
    }
  }

  return -1;
}

int main(void) {
  char search_term[MAX_TRACK_LENGTH];
  int found;

  // 1) Ask the user which track too look for
  ask_user(search_term);

  // 2) Search for the track
  found = search(search_term);
  if (found != -1) {
    printf("Found track %d: >>%s<<\n", found, TRACKS[found]);
  } else {
    printf("Track not found\n");
  }

  return 0;
}
