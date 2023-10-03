#include <stdio.h>

int main() {
  int x = 2023;

  int eredmeny = 0;
  while (x != 0) {
    eredmeny = eredmeny * 100 + (x % 10) * 10;
    x /= 10;
  }
  printf("%i", eredmeny);
  return 0;
}
