#include <stdio.h>
#include <limits.h>

void fel1(int *a, int len);
int find(int *arr, int len, int target);
int findMostOcc(int *arr, int len);

int main() {
  int a[] = {3, 6, 12, 18, 20, 4, 8, 9, 10, 13};
  int lena = sizeof(a) / sizeof(a[0]);

  // 1. feladat
  fel1(a, lena);

  // 2. feladat
  int pos = find(a, lena, 4);
  if (pos < 0) {
    printf("Nincs ilyen elem a tombben\n");
  } else {
    printf("Pozicio: %i\n", pos);
  }

  // 3. feladat
  int b[] = {1, 2, 3, 4, 3, 4, 1, 2, 5, 5, 4};
  printf("Leggyakoribb: %i", findMostOcc(b, sizeof(b) / sizeof(b[0])));
  return 0;
}

void fel1(int *a, int len) {
  int even[20];
  int odd[20];
  int neven = 0;
  int nodd = 0;
  printf("Array: ");
  for (int i = 0; i < len; i++) {
    if (a[i] % 2 == 0) {
      even[neven++] = a[i];
    } else {
      odd[nodd++] = a[i];
    }
    printf("%i ", a[i]);
  }
  printf("\nOdd: ");
  for (int i = 0; i < nodd; i++) {
    printf("%i ", odd[i]);
  }
  printf("\nEven: ");
  for (int i = 0; i < neven; i++) {
    printf("%i ", even[i]);
  }
  printf("\n");
}

int find(int *arr, int len, int target) {
  for (int i = 0; i < len; i++) {
    if (arr[i] == target) {
      return i;
    }
  }
  return -1;
}

int findMostOcc(int *arr, int len) {
  if (len == 0) {
    return -1;
  }
  int occur[100] = {0};
  for (int i = 0; i < len; i++) {
    occur[arr[i]]++;
  }
  int max = INT_MIN;
  int maxpos = INT_MIN;
  for (int i = 0; i < sizeof(occur) / sizeof(occur[0]); i++) {
    if (occur[i] > max) {
      max = occur[i];
      maxpos = i;
    }
  }
  return maxpos;
}
