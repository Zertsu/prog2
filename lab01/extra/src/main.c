#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *f = fopen("../input.txt", "r");
  if (f == NULL) {
    return 1;
  }
  int n;
  fscanf(f, "%i", &n);
  int *s = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    fscanf(f, "%i", &s[i]);
  }
  int max;
  fscanf(f, "%i", &max);

  int jumps = 0;
  int curPos = 0;

  while (curPos < n - 1) {
    int nextPos = curPos + max;
    if (nextPos >= n) {
      nextPos = n - 1;
    }
    while (nextPos > curPos && s[nextPos] != 1) {
      nextPos--;
    }
    if (nextPos == curPos) {
      printf("-1\n");
      return 0;
    }
    curPos = nextPos;
    jumps++;
  }
  printf("%i\n", jumps);
  return 0;
}
