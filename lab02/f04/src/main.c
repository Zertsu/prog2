#include <stdio.h>

int main() {
  int n;
  scanf("%i", &n);
  for (int i = 1; i * i < n; i++) {
    printf("%i ", i * i);
  }
  return 0;
}
