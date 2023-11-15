#include "Student.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void freadStudent(FILE *f, Student *s) {
  char tmp[128];
  fgets(tmp, 128, f);
  *strchr(tmp, '\n') = 0;
  strncpy(s->name, tmp, 20);
  fscanf(f, "%s %i %i", s->tel, &s->age, &s->nGrades);
  float sum = 0;
  for (int i = 0; i < s->nGrades; i++) {
    fscanf(f, "%f", &(s->grades[i]));
    sum += s->grades[i];
  }
  s->averageGrade = sum / s->nGrades;
  // After the fscanf a \n reamains on the current line, this clears it
  fgets(tmp, 128, f);
}

void freadStudents(FILE *f, Student **s, int *len) {
  char tmp[128];
  int n;
  fscanf(f, "%i\n", &n);
  Student *o = (Student *)malloc(sizeof(Student) * n);
  if (o == NULL) {
    exit(2);
  }
  for (int i = 0; i < n; i++) {
    freadStudent(f, &o[i]);
  }
  *s = o;
  *len = n;
}

void printStudent(Student s) {
  printf("%s: %s Age: %i Grades: ", s.name, s.tel, s.age);
  for (int i = 0; i < s.nGrades; i++) {
    printf("%.0f ", s.grades[i]);
  }
  printf("Avg: %.2f\n", s.averageGrade);
}

void printStudents(Student *s, int len) {
  for (int i = 0; i < len; i++) {
    printStudent(s[i]);
  }
}

int getMatchingDigits(Student *s, int len, char *str) {
  int cmplen = strlen(str);
  int sum = 0;
  for (int i = 0; i < len; i++) {
    if (memcmp(str, s[i].tel, cmplen) == 0) {
      sum++;
    }
  }
  return sum;
}

int StudentCmp(const void *a, const void *b) {
  Student *sa = (Student *)a;
  Student *sb = (Student *)b;
  return strcmp(sa->name, sb->name);
}

Student *findStudentByName(Student *s, int len, char *name) {
  for (int i = 0; i < len; i++) {
    if (strcmp(s[i].name, name) == 0) {
      return &s[i];
    }
  }
  return NULL;
}

Student *findBestAvgStudent(Student *s, int len) {
  Student *o = NULL;
  float max = -1;
  for (int i = 0; i < len; i++) {
    if (s[i].averageGrade > max) {
      o = &s[i];
      max = o->averageGrade;
    }
  }
  return o;
}

Student *findOldestStudent(Student *s, int len) {
  int max = INT_MIN;
  Student *o = NULL;
  for (int i = 0; i < len; i++) {
    if (s[i].age > max) {
      o = &s[i];
      max = o->age;
    }
  }
  return o;
}

Student *findYoungestStudent(Student *s, int len) {
  int min = INT_MAX;
  Student *o = NULL;
  for (int i = 0; i < len; i++) {
    if (s[i].age < min) {
      o = &s[i];
      min = o->age;
    }
  }
  return o;
}
