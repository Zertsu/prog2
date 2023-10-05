#include <stdio.h>

int main() {
  int n = 5;
  int a[] = {1, 6, 9, 2, 5};

  int c = 1;
  while (n > 0) {
    int a = n + 1;
    c = c + a;
    n = n - 1;
  }
  printf("%i", c);
  return 0;
}
