#include <stdio.h>
#include <string.h>

#include "Library.h"

void readBooks(Library *lib, FILE *f);
void readUsers(Library *lib, FILE *f);
int ui(Library *lib);
void printHelp(Library *lib);

int main() {
  Library l = initLibrary();

  FILE *f = fopen("../books.txt", "r");
  readBooks(&l, f);
  fclose(f);
  f = fopen("../users.txt", "r");
  readUsers(&l, f);
  fclose(f);

  while (ui(&l)) {
  }

  return 0;
}

void readBooks(Library *lib, FILE *f) {
  char t[256];
  int n;
  fgets(t, 256, f);
  sscanf(t, "%i", &n);
  for (int i = 0; i < n; i++) {
    Book b;
    fgets(b.title, 64, f);
    fgets(b.author, 64, f);
    fgets(b.ISBN, 16, f);

    *strchr(b.title, '\n') = 0;
    *strchr(b.author, '\n') = 0;
    *strchr(b.ISBN, '\n') = 0;
    addBook(lib, &b);
  }
}

void readUsers(Library *lib, FILE *f) {
  char t[256];
  int n;
  fgets(t, 256, f);
  sscanf(t, "%i", &n);
  for (int i = 0; i < n; i++) {
    User u;
    fgets(t, 64, f);
    sscanf(t, "%i", &u.id);
    fgets(u.name, 64, f);

    *strchr(u.name, '\n') = 0;
    addUser(lib, &u);
  }
}

typedef struct {
  char name[16];
  void (*func)(Library *);
} Command;

Command coms[] = {{"help", printHelp},        {"list books", printAllBooks},
                  {"list users", printUsers}, {"list loans", printLoans},
                  {"add book", readBooki},    {"add user", readUseri},
                  {"add loan", readLoani},    {"return loan", retLoani}};

int ui(Library *lib) {
  char cli[256];
  char *c = cli;
  printf("$ ");
  fgets(cli, 128, stdin);
  *strchr(cli, '\n') = 0;
  for (int i = 0; i < sizeof(coms) / sizeof(coms[0]); i++) {
    if (!strcmp(cli, "exit")) {
      return 0;
    }
    if (!strcmp(cli, coms[i].name)) {
      coms[i].func(lib);
      break;
    }
  }
  return 1;
}

void printHelp(Library *lib) {
  printf("Commnads:\n");
  for (int i = 0; i < sizeof(coms) / sizeof(coms[0]); i++) {
    printf("  %s\n", coms[i].name);
  }
  printf("  exit\n");
}
