#include <math.h>
#include <stdio.h>

int teljes(int n);

int n = 7;
int p = 150;
int q = 15;
int a[] = {15, 196, 23, 88, 100, 121, 4};

int main() {
  int szamol = 0;
  int eredmeny = 0;

  for (int i = 0; i < n; i++) {
    if (a[i] < p && a[i] > q) {
      if (teljes(a[i])) {
        szamol = szamol + 1;
        eredmeny = eredmeny + a[i];
        printf("%i ", a[i]);
      }
    }
  }
  printf("\n%i %i %i\n", szamol, eredmeny, n - szamol);
  return 0;
}

int teljes(int n) {
  if (n >= 0) {
    long long sr = sqrt(n);
    return (sr * sr == n);
  }

  return 0;
}
