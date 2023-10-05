#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  scanf("%i", &n);
  int count = 0;
  for (int i = 0, par = 0; i < n; i++, par = !par) {
    int v;
    scanf("%i", &v);
    if (v % 2 == par) {
      count++;
    }
  }
  printf("%i", count);
  return 0;
}
