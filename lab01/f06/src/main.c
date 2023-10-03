#include <stdio.h>
#include <string.h>

float vowRatio(const char *str);

int main() {
  char *strs[] = {"aeiou", "qwrtpsdfghjklzxcvbnm", "aesdik", "abb", "eec"};
  for (int i = 0; i < sizeof(strs) / sizeof(strs[0]); i++) {
    printf("%s: %.3f\n", strs[i], vowRatio(strs[i]));
  }
  return 0;
}

float vowRatio(const char *str) {
  char *vows = "aeiouAEIOU";
  int len = 0;
  int vow = 0;
  while (*str) {
    if (strchr(vows, *str) != 0) {
      vow++;
    }
    str++;
    len++;
  }
  return (float)vow / len;
}
