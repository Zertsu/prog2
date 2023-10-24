#include "Library.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initArray(void **arr, ArrInfo *info, int elementSize,
               int initialCapacity) {
  *arr = malloc(elementSize * initialCapacity);
  if (!*arr) {
    exit(1);
  }

  info->capacity = initialCapacity;
  info->size = 0;
  info->elementSize = elementSize;
}

void addToArray(void **arr, ArrInfo *info, void *element) {
  if (info->capacity == info->size) {
    info->capacity += info->capacity / 2;
    *arr = realloc(arr, info->elementSize * info->capacity);
    if (!*arr) {
      exit(1);
    }
  }
  memcpy(*arr + info->elementSize * info->size++, element, info->elementSize);
}

void removeFromArray(void **arr, ArrInfo *info, int n) {
  if (info->size <= n || n > 0) {
    return;
  }
  memmove(arr + (info->elementSize * n), arr + (info->elementSize * (n + 1)),
          info->elementSize * (info->size - n - 1));
  info->size--;
}

int dateCmp(Date *a, Date *b) {
  if (a->year != b->year) {
    return a->year < b->year ? 1 : -1;
  }
  if (a->month != b->month) {
    return a->month < b->month ? 1 : -1;
  }
  if (a->day != a->day) {
    return a->day < b->day ? 1 : -1;
  }
  return 0;
}

Library initLibrary() {
  Library l;
  initArray((void **)&l.books, &l.bookI, sizeof(Book), 4);
  initArray((void **)&l.users, &l.userI, sizeof(User), 4);
  initArray((void **)&l.loans, &l.loanI, sizeof(Loan), 4);
  return l;
}

void addBook(Library *lib, Book *book) {
  addToArray((void **)&lib->books, &lib->bookI, book);
}

void addUser(Library *lib, User *user) {
  addToArray((void **)&lib->users, &lib->userI, user);
}

int loanBook(Library *lib, User *User, Book *book, Date lendDate,
             Date retDate) {
  for (int i = 0; i < lib->loanI.size; i++) {
    if (&lib->books[i] == book) {
      return 0;
    }
  }
  Loan lo;
  lo.book = book;
  lo.user = User;
  lo.lendDate = lendDate;
  lo.returnDate = retDate;
  addToArray((void **)&lib->loans, &lib->loanI, &lo);
}

int returnBook(Library *lib, Book *book, Date actReturnDate) {
  for (int i = 0; i < lib->loanI.size; i++) {
    if (&lib->loans[i].book == &book) {
      removeFromArray((void **)&lib->loans, &lib->loanI, i);
      return dateCmp(&lib->loans[i].returnDate, &actReturnDate) != 1;
    }
  }
  return -1;
}

void printDate(Date *date) {
  printf("%04i.%02i.%02i", date->year, date->month, date->day);
}

void printBook(Book *book) {
  printf("\"%s\" by %s (%s)", book->title, book->author, book->ISBN);
}

void printLoan(Loan *loan) {
  printf("Loan: %s - %s by %s ", loan->user->name, loan->book->title,
         loan->book->author);
  printDate(&loan->lendDate);
  printf(" to ");
  printDate(&loan->returnDate);
  ;
}

void printUser(User *user) { printf("%s (%i)", user->name, user->id); }

User *findUserById(Library *lib, int id) {
  for (int i = 0; i < lib->userI.size; i++) {
    if (lib->users[i].id == id) {
      return &lib->users[i];
    }
  }
  return NULL;
}

void printLoansByUser(Library *lib, int userId) {
  User *user = findUserById(lib, userId);
  for (int i = 0; i < lib->loanI.size; i++) {
    if (lib->loans[i].user == user) {
      printLoan(&lib->loans[i]);
      printf("\n");
    }
  }
}

void printAllBooks(Library *lib) {
  for (int i = 0; i < lib->bookI.size; i++) {
    printBook(&lib->books[i]);
    printf("\n");
  }
}

void printDueLoans(Library *lib, Date curDate) {
  for (int i = 0; i < lib->loanI.size; i++) {
    if (dateCmp(&lib->loans[i].returnDate, &curDate) == 1) {
      printLoan(&lib->loans[i]);
    }
  }
}

void printUsers(Library *lib) {
  for (int i = 0; i < lib->userI.size; i++) {
    printUser(&lib->users[i]);
    printf("\n");
  }
}

void printLoans(Library *lib) {
  for (int i = 0; i < lib->loanI.size; i++) {
    printLoan(&lib->loans[i]);
    printf("\n");
  }
}

Date readDatei() {
  Date o;
  scanf("%i%i%i", &o.year, &o.month, &o.day);
  return o;
}

void readBooki(Library *lib) {
  Book b;
  printf("Title: ");
  fgets(b.title, 64, stdin);
  printf("Author: ");
  fgets(b.author, 64, stdin);
  printf("ISBN: ");
  fgets(b.ISBN, 16, stdin);
  *strchr(b.title, '\n') = 0;
  *strchr(b.author, '\n') = 0;
  *strchr(b.ISBN, '\n') = 0;
  addBook(lib, &b);
}

void readUseri(Library *lib) {
  User u;
  char temp[16];
  printf("Name: ");
  fgets(u.name, 64, stdin);
  *strchr(u.name, '\n') = 0;
  printf("id: ");
  fgets(temp, 16, stdin);
  sscanf(temp, "%i", &u.id);
  addUser(lib, &u);
}

void readLoani(Library *lib) {
  char temp[128];
  Loan l;
  int n;
  for (int i = 0; i < lib->bookI.size; i++) {
    printf("%02i: %s\n", i, lib->books[i].title);
  }
  printf("Choose book: ");
  fgets(temp, 128, stdin);
  sscanf(temp, "%i", &n);
  l.book = &lib->books[n];
  for (int i = 0; i < lib->userI.size; i++) {
    printf("%02i: %s\n", i, lib->users[i].name);
  }
  printf("Choose user: ");
  fgets(temp, 128, stdin);
  sscanf(temp, "%i", &n);
  l.user = &lib->users[n];
  printf("Enter loan date: ");
  l.lendDate = readDatei();
  printf("Enter return date: ");
  l.returnDate = readDatei();
  loanBook(lib, l.user, l.book, l.lendDate, l.returnDate);
}

void retLoani(Library *lib) {
  char temp[128];
  int n;
  for (int i = 0; i < lib->loanI.size; i++) {
    printf("%02i: ", i);
    printLoan(&lib->loans[i]);
    printf("\n");
  }
  printf("Choose loan: ");
  fgets(temp, 128, stdin);
  sscanf(temp, "%i", &n);
  printf("Enter actual return date: ");
  Date ret = readDatei();
  if (returnBook(lib, &lib->books[n], ret)) {
    printf("Book was returned on time\n");
  } else {
    printf("Book was returned late\n");
  }
}
