#include <stdio.h>

int countWords(char *str);

int main() {
  char s[] = "In Africa every 60 seconds a minute passes.";
  printf("%i - %s", countWords(s), s);
  return 0;
}

int countWords(char *s) {
  int state = 0;
  int count = 0;
  while (*s) {
    if ((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z') ||
        (*s >= '0' && *s <= '9')) {
      if (state == 0) {
        count++;
        state = 1;
      }
    } else {
      state = 0;
    }
    s++;
  }
  return count;
}
