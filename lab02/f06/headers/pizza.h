#pragma once

#include <stdio.h>

typedef struct {
  char name[50];
  char ingredients[200];
  float price;
} Pizza;

void readPizza(Pizza *pizza);
void freadPizza(FILE *file, Pizza *pizza);
void printPizza(Pizza pizza);
void fprintPizza(FILE *file, Pizza pizza);

int priceCmp(const void *a, const void *b);
