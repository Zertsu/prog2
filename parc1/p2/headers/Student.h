#pragma once

#include <stdio.h>

typedef struct {
  char name[21];
  char tel[11];
  int age;
  int nGrades;
  float grades[10];
  float averageGrade;
} Student;

void freadStudent(FILE *f, Student *s);
void freadStudents(FILE *f, Student **s, int *len);

void printStudent(Student s);
void printStudents(Student *s, int len);

int getMatchingDigits(Student *s, int len, char *str);

int StudentCmp(const void *a, const void *b);

Student *findStudentByName(Student *s, int len, char *name);
Student *findBestAvgStudent(Student *s, int len);
Student *findOldestStudent(Student *s, int len);
Student *findYoungestStudent(Student *s, int len);
