#include <stdio.h>

int main() {
  int a[3][3];
  FILE *f = fopen("../input.txt", "r");
  if (!f) {
    return -1;
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      fscanf(f, "%i", &a[i][j]);
    }
  }
  for (int i = 0; i < 2; i++) {
    a[0][i] = a[0][i] + 1;
    a[i][0] = a[i][0] - 1;
  }
  for (int i = 0; i < 2; i++) {
    a[i][2] = a[i][2] + 1;
    a[2][i] = a[2][i] - 1;
  }
  for (int i = 2; i > 0; i--) {
    a[2][i] = a[2][i] + 1;
    a[i][2] = a[i][2] - 1;
  }
  for (int i = 2; i > 0; i--) {
    a[i][0] = a[i][0] + 1;
    a[0][i] = a[0][i] - 1;
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%i ", a[i][j]);
    }
    printf("\n");
  }

  return 0;
}
