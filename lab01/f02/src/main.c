#include <stdio.h>

int main() {
  int x = 19072023;
  int y = 3;

  int eredmeny = 0;
  while (x != 0) {
    if ((x % 10) % y == 0) {
      eredmeny = eredmeny * 10 + (x % 10) / y;
    }
    x = x / 10;
  }
  printf("%i", eredmeny);
  return 0;
}
