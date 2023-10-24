#include <stdio.h>
#include <stdlib.h>

void sortIntArr(int *arr, int len);
int intCmp(const void *a, const void *b);
void printIntArr(int *arr, int len);

int main() {
  int a[] = {2, 5, 8, 19, 14, 3, 15};
  int len = sizeof(a) / sizeof(a[0]);
  printIntArr(a, len);
  sortIntArr(a, len);
  printIntArr(a, len);
  return 0;
}

void sortIntArr(int *arr, int len) { qsort(arr, len, sizeof(int), intCmp); }

int intCmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

void printIntArr(int *arr, int len) {
  for (int i = 0; i < len; i++) {
    printf("%i ", arr[i]);
  }
  printf("\n");
}
