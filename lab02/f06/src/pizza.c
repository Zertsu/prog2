#include "pizza.h"

#include <stdlib.h>
#include <string.h>

void readPizza(Pizza *pizza) { freadPizza(stdin, pizza); }

void freadPizza(FILE *file, Pizza *pizza) {
  fscanf(file, "%s", &pizza->name);
  fscanf(file, "%s", &pizza->ingredients);
  fscanf(file, "%f", &pizza->price);
}

void printPizza(Pizza pizza) { fprintPizza(stdout, pizza); }
void fprintPizza(FILE *file, Pizza pizza) {
  fprintf(file, "%s %s %.0f\n", pizza.name, pizza.ingredients, pizza.price);
}

int priceCmp(const void *a, const void *b) {
  return ((Pizza *)a)->price > ((Pizza *)b)->price;
}
