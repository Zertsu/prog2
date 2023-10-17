#include "Book.h"

void printBook(Book book) { fprintBook(stdout, book); }

void fprintBook(FILE *file, Book book) {
  fprintf(file, "\"%s\" by %s (%i)\n", book.title, book.author,
          book.releaseYear);
}

void printBooks(Book *books, int len) {
  for (int i = 0; i < len; i++) {
    fprintBook(stdout, books[i]);
  }
}

void fprintBooks(FILE *file, Book *books, int len) {
  for (int i = 0; i < len; i++) {
    fprintBook(file, books[i]);
  }
}
