#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reverseString(char *s);

int main() {
  char str[] = "Hewwo, World!";
  char *rstr = reverseString(str);
  printf("%s\n%s", str, rstr);
  free(rstr);
  return 0;
}

char *reverseString(char *s) {
  int len = strlen(s);
  char *o = (char *)malloc(sizeof(char) * (len + 1));
  for (char *from = s + len - 1, *to = o; from >= s; from--, to++) {
    *to = *from;
  }
  o[len] = '\x00';
  return o;
}
