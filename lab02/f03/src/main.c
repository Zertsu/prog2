#include <stdio.h>

int main() {
  int a, b;
  scanf("%i%i", &a, &b);
  if (a < 10 || a > 99 || b < 10 || b > 99) {
    return -1;
  }
  int a1 = a % 10;
  int a2 = a / 10;
  int b1 = b % 10;
  int b2 = b / 10;

  if (a2 > b2 && a1 + a2 > b1 + b2) {
    printf("%i", a);
  } else if (a2 < b2 && a1 + a2 < b1 + b2) {
    printf("%i", b);
  } else {
    printf("NINCS VEZERSZAM");
  }
  return 0;
}
