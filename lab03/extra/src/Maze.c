#include "Maze.h"

#include <stdio.h>

Pos dirVec[] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

void printMaze(cT **m, Pos size, char *pathStr) {
  for (int i = 0; i < size.y; i++) {
    for (int j = 0; j < size.x; j++) {
      char *o = " ";
      if (isWall(m[i][j])) {
        o = "#";
      } else if (isPathBit(m[i][j])) {
        o = pathStr;
      }
      printf("%s", o);
    }
    printf("\n");
  }
}

void findEnterExit(cT **m, Pos size, Pos *enter, Pos *exit, Dir *enterDir,
                   Dir *exitDir) {
  int found = 0;
  Pos *out[] = {exit, enter};
  Dir *outd[] = {exitDir, enterDir};
  Pos p = {0, 0};
  Pos v[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  int state = 0;
  while (found != 2) {
    if (!isWall(m[p.y][p.x])) {
      *outd[found] = state;
      *out[found++] = p;
    }
    Pos tempp = addPos(p, v[state]);
    if (tempp.x >= size.x || tempp.x < 0 || tempp.y >= size.y || tempp.y < 0) {
      p = addPos(p, v[++state]);
    } else {
      p = tempp;
    }
  }
}

void mapMaze(cT **m, Pos pos, cT dist, Dir from, Pos exit) {
  if (isWall(m[pos.y][pos.x])) {
    // Entered into a wall, go back
    return;
  }
  if (getDist(m[pos.y][pos.x]) <= dist) {
    // Another path is already shorter
    return;
  }
  // Current path shortest, save it
  setDist(&m[pos.y][pos.x], dist);
  setDir(&m[pos.y][pos.x], from);
  if (eqsPos(pos, exit)) {
    // At the exit, nowhere to go from here
    return;
  }
  dist++;
  for (int i = 0; i < 4; i++) {
    if (i != from) {
      mapMaze(m, addPos(pos, dirVec[i]), dist, revDir(i), exit);
    }
  }
}

void markPath(cT **m, Pos exit, Pos enter) {
  Pos p = exit;
  while (!eqsPos(p, enter)) {
    setPathBit(&m[p.y][p.x]);
    p = addPos(p, dirVec[getDir(m[p.y][p.x])]);
  }
  setPathBit(&m[p.y][p.x]);
}

void markVisited(cT **m, Pos size) {
  for (int i = 0; i < size.y; i++) {
    for (int j = 0; j < size.x; j++) {
      if (isVisited(m[i][j])) {
        setPathBit(&m[i][j]);
      }
    }
  }
}

Pos addPos(Pos a, Pos b) { return (Pos){.x = a.x + b.x, .y = a.y + b.y}; }
int eqsPos(Pos a, Pos b) { return a.x == b.x && a.y == b.y; }
int isWall(cT c) { return c & 1; }
cT getDist(cT c) { return c >> 4; }
void setDist(cT *c, cT dist) { *c = (*c & 0b1111) | dist << 4; }
void setDir(cT *c, Dir dir) { *c = (*c & ~0b110) | dir << 1; }
Dir getDir(cT c) { return (c & 0b110) >> 1; }
Dir revDir(Dir dir) { return (dir + 2) % 4; }
int isVisited(cT c) { return (c & ~0b1111) != ~0b1111; }
void setPathBit(cT *c) { *c |= 1 << 3; }
int isPathBit(cT c) { return (c >> 3) & 1; }
