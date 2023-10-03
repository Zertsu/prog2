#include <stdio.h>

int main() {
  int j;
  char *o;
  scanf("%i", &j);
  if (j < 0 || j > 100) {
    o = "nem ervenyes jegy";
  } else if (j < 50) {
    o = "elegtelen";
  } else if (j < 65) {
    o = "elegseges";
  } else if (j < 80) {
    o = "kozepes";
  } else if (j < 90) {
    o = "jo";
  } else {
    o = "jeles";
  }
  printf("Jegy: %s", o);
  return 0;
}
