#pragma once

#include <stdio.h>

typedef struct {
  char title[64];
  char author[64];
  int releaseYear;
} Book;

void printBook(Book book);
void fprintBook(FILE *file, Book book);

void printBooks(Book *books, int len);
void fprintBooks(FILE *file, Book *books, int len);
