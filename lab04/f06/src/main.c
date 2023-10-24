#include <stdio.h>

int countChar(char *str, char ch);

int main() {
  char s[] = "Hewwo, World!";
  char ch = 'o';
  printf("%c:%i - %s", ch, countChar(s, ch), s);
  return 0;
}

int countChar(char *str, char ch) {
  int o = 0;
  while (*str) {
    if (*str == ch) {
      o++;
    }
    str++;
  }
  return o;
}
