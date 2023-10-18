#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "Maze.h"

void readMaze(FILE *file, cT ***m, Pos *size);
void freeMaze(cT **m, Pos size);

int main() {
  char *files[] = {"../maze20.txt", "../maze20blocked.txt", "../mazeAsym.txt",
                   "../maze100.txt"};
  for (int i = 0; i < sizeof(files) / sizeof(files[0]); i++) {
    // read maze
    cT **m;
    Pos s;
    FILE *f = fopen(files[i], "r");
    readMaze(f, &m, &s);
    fclose(f);

    // find enter and exit
    Pos enter, exit;
    Dir enterDir, ExitDir;
    findEnterExit(m, s, &enter, &exit, &enterDir, &ExitDir);

    // map maze
    mapMaze(m, enter, 0, revDir(enterDir), exit);

    // Check for solution
    if (isVisited(m[exit.y][exit.x])) {
      markPath(m, exit, enter);
      printMaze(m, s, "\x1b[32m+\033[0m");
    } else {
      markVisited(m, s);
      printMaze(m, s, "\x1b[31m+\033[0m");
    }
    printf("\n\n\n");

    // free memory
    freeMaze(m, s);
  }

  return 0;
}

void readMaze(FILE *file, cT ***m, Pos *size) {
  fscanf(file, "%i%i\n", &size->x, &size->y);
  *m = (cT **)malloc(sizeof(cT *) * size->y);
  if (!*m) {
    exit(1);
  }
  for (int i = 0; i < size->y; i++) {
    char temp[128];
    fgets(temp, 128, file);
    (*m)[i] = (cT *)malloc(sizeof(cT) * size->x);
    if (!(*m)[i]) {
      exit(1);
    }
    for (int j = 0; j < size->x; j++) {
      (*m)[i][j] = (temp[j] == '#' ? 1 : 0) | ~0b1111;
    }
  }
}

void freeMaze(cT **m, Pos size) {
  for (int i = 0; i < size.y; i++) {
    free(m[i]);
  }
  free(m);
}
