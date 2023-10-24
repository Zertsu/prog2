#include <stdio.h>
#include <string.h>

int mystrlen(char *c);

int main() {
  char s[] = "Hewwo, World!";
  printf("%i - %s\n", mystrlen(s), s);
  return 0;
}

int mystrlen(char *c) {
  return strlen(c);
  // The library implementation is way better but here's mine
  //   char *s = c;
  //   while (*s) {
  //     s++;
  //   }
  //   return s - c;
}
