#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pizza.h"

int main() {
  FILE *f = fopen("../pizza.txt", "r");
  if (!f) {
    return 1;
  }
  int n;
  fscanf(f, "%i", &n);
  Pizza *p = (Pizza *)malloc(sizeof(Pizza) * n);
  for (int i = 0; i < n; i++) {
    freadPizza(f, &p[i]);
  }
  fclose(f);
  qsort(p, n, sizeof(Pizza), priceCmp);
  f = fopen("../non-pizza-szosz.out.txt", "w");
  if (!f) {
    return 2;
  }
  for (int i = 0; i < n; i++) {
    if (!strstr(p[i].ingredients, "pizza-szosz")) {
      fprintPizza(f, p[i]);
    }
    if (p[i].price < 35) {
      printPizza(p[i]);
    }
  }
  free(p);
  return 0;
}
