#include <stdio.h>
#include <stdlib.h>

int main() {
  // freopen("../input.txt", "r", stdin);

  printf("Size:");
  int sX, sY;
  scanf("%i%i", &sX, &sY);
  int **m = malloc(sizeof(int) * sY);
  if (!m) {
    return 1;
  }
  int len = 0;
  for (int i = 0; i < sY; i++) {
    m[len] = (int *)malloc(sizeof(int) * sX);
    if (m[len] == 0) {
      return 1;
    }
    for (int j = 0; j < sX; j++) {
      scanf("%i", &m[len][j]);
    }
    int same = 0;
    for (int j = 0; j < len; j++) {
      same = 1;
      for (int k = 0; k < sX; k++) {
        if (m[len][k] != m[j][k]) {
          same = 0;
          break;
        }
      }
      if (same) {
        break;
      }
    }
    if (!same) {
      len++;
    } else {
      free(m[len]);
    }
  }

  printf("Result (filtered %i lines):\n", sY - len);
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < sX; j++) {
      printf("%i ", m[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < len; i++) {
    free(m[i]);
  }
  free(m);

  return 0;
}
