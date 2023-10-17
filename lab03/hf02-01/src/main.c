#include <stdio.h>
#include <stdlib.h>

int **createMatrix(int sX, int sY);
int **readMatrix(FILE *file, int sX, int sY);
void printMatrix(FILE *file, int **matrix, int sX, int sY);
int **sumMatrix(int **a, int **b, int sX, int sY);
int **mulMatrix(int **a, int **b, int sX, int sY);
void freeMatrix(int **m, int sY);

int main() {
  // freopen("../input.txt", "r", stdin);

  int sX, sY;
  printf("Size: ");
  scanf("%i%i", &sX, &sY);
  printf("First matrix:\n");
  int **mA = readMatrix(stdin, sX, sY);
  printf("Second matrix:\n");
  int **mB = readMatrix(stdin, sX, sY);

  int **sum = sumMatrix(mA, mB, sX, sY);
  int **mul = mulMatrix(mA, mB, sX, sY);

  printf("Sum:\n");
  printMatrix(stdout, sum, sX, sY);
  printf("Prod:\n");
  printMatrix(stdout, mul, sX, sY);

  int **stuff[] = {mA, mB, sum, mul};
  for (int i = 0; i < sizeof(stuff) / sizeof(stuff[0]); i++) {
    freeMatrix(stuff[i], sY);
  }

  return 0;
}

int **createMatrix(int sX, int sY) {
  int **o = (int **)malloc(sizeof(int *) * sY);
  if (!o) {
    exit(1);
  }
  for (int i = 0; i < sX; i++) {
    o[i] = (int *)malloc(sizeof(int) * sX);
    if (!o[i]) {
      exit(1);
    }
  }
  return o;
}

int **readMatrix(FILE *file, int sX, int sY) {
  int **o = (int **)malloc(sizeof(int *) * sY);
  if (!o) {
    exit(1);
  }
  for (int i = 0; i < sX; i++) {
    o[i] = (int *)malloc(sizeof(int) * sX);
    if (!o[i]) {
      exit(1);
    }
    for (int j = 0; j < sX; j++) {
      scanf("%i", &o[i][j]);
    }
  }
  return o;
}

void printMatrix(FILE *file, int **matrix, int sX, int sY) {
  for (int i = 0; i < sY; i++) {
    for (int j = 0; j < sX; j++) {
      printf("%4i ", matrix[i][j]);
    }
    printf("\n");
  }
}

int **sumMatrix(int **a, int **b, int sX, int sY) {
  int **o = createMatrix(sX, sY);
  for (int i = 0; i < sY; i++) {
    for (int j = 0; j < sX; j++) {
      o[i][j] = a[i][j] + b[i][j];
    }
  }
  return o;
}

int **mulMatrix(int **a, int **b, int sX, int sY) {
  if (sX != sY) {
    return NULL;
  }

  int **o = createMatrix(sX, sY);
  for (int i = 0; i < sY; i++) {
    for (int j = 0; j < sX; j++) {
      o[i][j] = 0;
      for (int k = 0; k < sX; k++) {
        o[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return o;
}

void freeMatrix(int **m, int sY) {
  for (int i = 0; i < sY; i++) {
    free(m[i]);
  }
  free(m);
}
