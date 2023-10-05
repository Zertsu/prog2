#include <stdio.h>
#include <string.h>

int main() {
  int n;
  scanf("%i", &n);
  char s[64];
  sprintf(s, "%i", n);
  char *end = s + strlen(s) - 1;

  for (char *i = end; i >= s; i--) {
    for (char *j = end; j >= i; j--) {
      printf("%c", *j);
    }
    printf("\n");
  }

  for (char *i = s; i <= end; i++) {
    for (char *j = s; j <= i; j++) {
      printf("%c", *j);
    }
    printf("\n");
  }
  return 0;
}
