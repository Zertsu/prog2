#include "Team.h"

#include <stdlib.h>

void freadTeam(FILE *f, Team *tar) {
  fscanf(f, "%s", tar->name);
  fscanf(f, "%i", &tar->points);
}

void freadTeams(FILE *f, Team **tar, int *len) {
  char tmp[128];
  int n;
  fgets(tmp, 128, f);
  sscanf(tmp, "%i", &n);
  Team *o = (Team *)malloc(sizeof(Team) * n);
  if (o == NULL) {
    exit(1);
  }
  for (int i = 0; i < n; i++) {
    freadTeam(f, &o[i]);
  }
  *tar = o;
  *len = n;
}

void printTeam(Team t) { printf("%s: %i\n", t.name, t.points); }

void printTeams(Team *t, int len) {
  for (int i = 0; i < len; i++) {
    printTeam(t[i]);
  }
}
