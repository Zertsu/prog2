#pragma once

#include <stdint.h>

typedef uint32_t cT;

typedef struct {
  int x;
  int y;
} Pos;

typedef enum { UP = 0, LEFT, DOWN, RIGHT } Dir;

void printMaze(cT **m, Pos size, char *pathStr);
void findEnterExit(cT **m, Pos size, Pos *enter, Pos *exit, Dir *enterDir,
                   Dir *exitDir);

void mapMaze(cT **m, Pos pos, cT dist, Dir from, Pos exit);
void markPath(cT **m, Pos exit, Pos enter);
void markVisited(cT **m, Pos size);

Pos addPos(Pos a, Pos b);
int eqsPos(Pos a, Pos b);
int isWall(cT c);
cT getDist(cT c);
void setDist(cT *c, cT dist);
void setDir(cT *c, Dir dir);
Dir getDir(cT c);
Dir revDir(Dir dir);
int isVisited(cT c);
void setPathBit(cT *c);
int isPathBit(cT c);
