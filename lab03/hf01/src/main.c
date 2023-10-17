#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isMirrorWord(char *word);
char *dec2bin(char *str);

int main() {
  char *strs[] = {"asdfghhgfdsa", "qweewq", "asdfghj"};
  for (int i = 0; i < sizeof(strs) / sizeof(strs[0]); i++) {
    printf("isMirrorWord(%s) -> %i\n", strs[i], isMirrorWord(strs[i]));
  }
  char *nums[] = {"125", "256", "255", "16813", "512"};
  for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
    char *tmp = dec2bin(nums[i]);
    printf("\"%s\":\"%s\"\n", nums[i], tmp);
    free(tmp);
  }

  return 0;
}

int isMirrorWord(char *word) {
  for (char *i = word, *j = word + strlen(word) - 1; i < j; i++, j--) {
    if (*i != *j) {
      return 0;
    }
  }
  return 1;
}

char *dec2bin(char *str) {
  const int blen = 64;
  int n = atoi(str);
  char *out = (char *)malloc(sizeof(char) * blen);
  int len = 0;
  for (int i = blen - 1; n != 0; i--) {
    out[i] = n & 1 ? '1' : '0';
    n >>= 1;
    len++;
  }
  memmove(out, out + blen - len, len);
  out[len] = 0;
  return out;
}
