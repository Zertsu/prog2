#include <stdio.h>
#include <stdlib.h>

void parosok_szama(int n, int m, int **arr, int *nr);

int main() {
  FILE *f = fopen("../input.txt", "r");
  int n, m;
  fscanf(f, "%i %i", &n, &m);
  int **arr = (int **)malloc(sizeof(int *) * n);
  if (arr == 0) {
    return 1;
  }
  for (int i = 0; i < n; i++) {
    arr[i] = (int *)malloc(sizeof(int) * m);
    if (arr[i] == 0) {
      return 1;
    }
    for (int j = 0; j < m; j++) {
      fscanf(f, "%i", &(arr[i][j]));
    }
  }
  int nr;
  parosok_szama(n, m, arr, &nr);
  printf("%i", nr);

  for (int i = 0; i < n; i++) {
    free(arr[i]);
  }
  free(arr);
  return 0;
}

void parosok_szama(int n, int m, int **arr, int *nr) {
  *nr = m;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[j][i] % 2 != 0) {
        (*nr)--;
        break;
      }
    }
  }
}
