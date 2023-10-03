#include <stdio.h>

int main() {
  int eredmeny1 = 0;
  int eredmeny2 = 0;
  int p = 1;

  int x;
  scanf("%i", &x);

  while (x != 0) {
    if (x < 0) {
      eredmeny1 = eredmeny1 * 10 + ((-1) * x);
    }
    if (x > 0) {
      eredmeny2 = eredmeny2 + x * p;
      p = p * 10;
    }
    scanf("%i", &x);
  }
  printf("%i  %i\n", eredmeny1, eredmeny2);
  return 0;
}

// Input: 1 -9 7 2 -3 4 5 -8 6 0
