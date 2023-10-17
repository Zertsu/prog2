#include <stdio.h>
#include <stdlib.h>

int cmpA(const void *a, const void *b);
int cmpB(const void *a, const void *b);

int main() {
  // freopen("../input.txt", "r", stdin);

  printf("Size:");
  int sX, sY;
  scanf("%i%i", &sX, &sY);
  int **m = malloc(sizeof(int) * sY);
  if (!m) {
    return 1;
  }
  for (int i = 0; i < sY; i++) {
    m[i] = (int *)malloc(sizeof(int) * sX);
    if (m[i] == 0) {
      return 1;
    }
    for (int j = 0; j < sX; j++) {
      scanf("%i", &m[i][j]);
    }
    qsort(m[i], sX, sizeof(int), i & 1 ? cmpA : cmpB);
  }

  printf("Result:\n");
  for (int i = 0; i < sY; i++) {
    for (int j = 0; j < sX; j++) {
      printf("%i ", m[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < sY; i++) {
    free(m[i]);
  }
  free(m);

  return 0;
}

int cmpA(const void *a, const void *b) { return *(int *)b - *(int *)a; }
int cmpB(const void *a, const void *b) { return *(int *)a - *(int *)b; }
