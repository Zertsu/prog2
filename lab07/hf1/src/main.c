#include <stdio.h>
#include <stdlib.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

int **allocMat(int s);
void freeMat(int **m, int s);
void printMatrix(int **m, int s);
void bfs(int s, int **m, int nn, int *cm);

int main() {
  FILE *f = fopen("../dir.txt", "r");
  if (!f) {
    exit(1);
  }
  int nn, ne;
  fscanf(f, "%i%i", &nn, &ne);
  int **m = allocMat(nn);
  for (int i = 0; i < ne; i++) {
    int x, y;
    fscanf(f, "%i%i", &x, &y);
    x--;
    y--;
    m[x][y] = 1;
  }
  fclose(f);
  printMatrix(m, nn);
  int *cm = (int *)calloc(sizeof(int), nn);
  int st;
  scanf("%i", &st);
  bfs(st - 1, m, nn, cm);
  freeMat(m, nn);
  return 0;
}

int **allocMat(int s) {
  int **o = (int **)calloc(s, sizeof(int));
  if (o == NULL) {
    exit(2);
  }
  for (int i = 0; i < s; i++) {
    o[i] = (int *)calloc(s, sizeof(int));
    if (!o[i]) {
      exit(2);
    }
  }
  return o;
}

void freeMat(int **m, int s) {
  for (int i = 0; i < s; i++) {
    free(m[i]);
  }
  free(m);
}

void printMatrix(int **m, int s) {
  for (int i = 0; i < s; i++) {
    for (int j = 0; j < s; j++) {
      printf("%i ", m[i][j]);
    }
    printf("\n");
  }
}

void bfs(int start, int **m, int nn, int *cm) {
  int *q = calloc(sizeof(int), nn);
  int qpop = 0, qpush = 0;
  q[qpush++] = start;
  cm[start] = GRAY;
  while (qpop < qpush) {
    int it = q[qpop++];
    printf("%i ", it + 1);
    for (int i = 0; i < nn; i++) {
      if (m[it][i] == 1 && cm[i] == WHITE) {
        q[qpush++] = i;
        cm[i] = GRAY;
      }
    }
    cm[it] = BLACK;
  }
  free(q);
}
