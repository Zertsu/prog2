#include <stdio.h>
#include <stdlib.h>

#include "Team.h"

int teamCmp(const void *a, const void *b);

int main() {
  FILE *f = fopen("../merkozes.txt", "r");
  if (!f) {
    exit(2);
  }
  Team *t;
  int len;
  freadTeams(f, &t, &len);
  fclose(f);

  printTeams(t, len);
  qsort(t, len, sizeof(Team), teamCmp);
  printf("\n");

  f = fopen("../sorrend.out.txt", "w");
  if (!f) {
    exit(2);
  }
  fprintf(f, "Rendezett sorrend: ");
  for (int i = 0; i < len; i++) {
    fprintf(f, "%s, ", t[i].name);
  }
  fprintf(f, "\nA legjobbak: %i\n", t[len - 1].points);
  fprintf(f, "A legrosszabbak a: %s\n", t[0].name);
  int sum = 0;
  for (int i = 0; i < len; i++) {
    sum += t[i].points;
  }
  fprintf(f, "A csapat atlaga: %.1f\n", (float)sum / len);

  fclose(f);
  free(t);
  return 0;
}

int teamCmp(const void *a, const void *b) {
  Team *at = (Team *)a;
  Team *bt = (Team *)b;
  return at->points - bt->points;
}
