#pragma once

typedef struct {
  int size;
  int capacity;
  int elementSize;
} ArrInfo;

typedef struct {
  int year;
  int month;
  int day;
} Date;

typedef struct {
  char title[64];
  char author[64];
  char ISBN[16];
} Book;

typedef struct {
  char name[64];
  int id;
} User;

typedef struct {
  Book *book;
  User *user;
  Date lendDate;
  Date returnDate;
} Loan;

typedef struct {
  Book *books;
  ArrInfo bookI;
  User *users;
  ArrInfo userI;
  Loan *loans;
  ArrInfo loanI;
} Library;

void initArray(void **arr, ArrInfo *info, int elementSize, int initialCapacity);
void addToArray(void **arr, ArrInfo *info, void *element);
void removeFromArray(void **arr, ArrInfo *info, int n);

int dateCmp(Date *a, Date *b);

Library initLibrary();
void addBook(Library *lib, Book *book);
void addUser(Library *lib, User *user);
int loanBook(Library *lib, User *User, Book *book, Date lendDate, Date retDate);
int returnBook(Library *lib, Book *book, Date actReturnDate);

void printDate(Date *date);
void printBook(Book *book);
void printLoan(Loan *loan);
void printUser(User *user);

User *findUserById(Library *lib, int id);
void printLoansByUser(Library *lib, int userId);
void printAllBooks(Library *lib);
void printDueLoans(Library *lib, Date curDate);
void printUsers(Library *lib);
void printLoans(Library *lib);

Date readDatei();
void readBooki(Library *lib);
void readUseri(Library *lib);
void readLoani(Library *lib);
void retLoani(Library *lib);
