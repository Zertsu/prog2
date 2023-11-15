#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Student.h"

int main() {
  Student *s;
  int len;
  FILE *f = fopen("../in.txt", "r");
  if (!f) {
    exit(1);
  }
  freadStudents(f, &s, &len);
  fclose(f);

  printf("a) b)\n");
  printStudents(s, len);

  char *telstr = "074";
  printf("\nc) %s-el kezdodo diaknak telefonszamanak a szama: %i\n", telstr,
         getMatchingDigits(s, len, telstr));

  qsort(s, len, sizeof(Student), StudentCmp);
  printf("\nd)\n");
  printStudents(s, len);

  char *tarstr = "Pal Tamas";
  printf("\ne) %s keresese: ", tarstr);
  Student *tars = findStudentByName(s, len, tarstr);
  if (tars) {
    printStudent(*tars);
  } else {
    printf("Student not found\n");
  }

  printf("\nf) Legjobb atlagu tanulo: %s\n", findBestAvgStudent(s, len)->name);

  printf("\ng) Students between the oldest and youngest:\n");
  int maxage = findOldestStudent(s, len)->age;
  int minage = findYoungestStudent(s, len)->age;
  for (int i = 0; i < len; i++) {
    if (s[i].age > minage && s[i].age < maxage) {
      printStudent(s[i]);
    }
  }

  free(s);
  return 0;
}
