#pragma once

#include <stdio.h>

typedef struct {
  char name[64];
  int points;
} Team;

void freadTeam(FILE *f, Team *tar);
void freadTeams(FILE *f, Team **tar, int *len);
void printTeam(Team t);
void printTeams(Team *t, int len);
