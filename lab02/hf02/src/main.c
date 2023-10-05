#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    return 1;
  }
  int n;
  sscanf(argv[1], "%i", &n);
  if (n != argc - 2) {
    return 2;
  }
  for (int i = 0, j = argc - 3; i < j; i++, j--) {
    if (strlen(argv[2 + i]) != strlen(argv[2 + j])) {
      printf("nem");
      return 0;
    }
  }
  printf("igen");
  return 0;
}
