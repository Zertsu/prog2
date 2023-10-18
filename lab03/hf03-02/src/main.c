#include <stdio.h>
#include <string.h>

#include "Book.h"

void addBook(Book *books, int pos, char *title, char *author, int year);

int main() {
  Book b[10];
  addBook(b, 0, "Structs in C", "A smart guy", 2012);
  addBook(b, 1, "Functions in C", "Other smart guy", 2011);
  addBook(b, 2, "Out of ideas", "Not so smart guy", 2015);

  printBooks(b, 3);
  return 0;
}

void addBook(Book *books, int pos, char *title, char *author, int year) {
  strcpy(books[pos].title, title);
  strcpy(books[pos].author, author);
  books[pos].releaseYear = year;
}
