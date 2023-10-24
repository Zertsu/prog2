#include <stdio.h>

int insSumToN(int n);

int main() {
  for (int i = 0; i <= 50; i++) {
    printf("%2i : %i\n", i, insSumToN(i));
  }
  return 0;
}

int insSumToN(int n) {
  if (n < 1) {
    return 0;
  }
  return ((1 + n) * n) / 2;
}
