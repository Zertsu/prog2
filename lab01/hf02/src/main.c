#include <stdio.h>

int main() {
  int n;
  scanf("%i", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      printf("6 ");
    }
    printf("0 ");
    for (int j = i + 1; j < n; j++) {
      printf("9 ");
    }
    printf("\n");
  }
  return 0;
}
