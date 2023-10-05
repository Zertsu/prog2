#include <stdio.h>
#include <stdlib.h>

int main() {
  int a, b, c;
  scanf("%i%i%i", &a, &b, &c);

  // Trying for perfect fit
  if ((a % b) % c == 0) {
    printf("%i %i 0", a / b, (a % b) / c);
    return 0;
  }

  // Trying fewer and fewer long cuts
  int nb = a / b;
  int *remainders = (int *)calloc(sizeof(char), c);
  int bestnb = nb;
  int bestrem = (a - nb * b) % c;
  while (nb > 0) {
    nb--;
    int rem = (a - nb * b) % c;
    if (rem == 0) {
      // Found the perfect fit
      printf("%i %i 0", nb, (a - b * nb) / c);
      return 0;
    }
    // If this is the best solution so far, save it
    if (rem < bestrem) {
      bestnb = nb;
      bestrem = rem;
    }
    // If we already saw the current reminder
    // stop, because we won't find a better answer
    if (remainders[rem] != 0) {
      break;
    } else {
      remainders[rem] = 1;
    }
  }

  free(remainders);

  printf("%i %i %i", bestnb, (a - b * bestnb) / c, (a - b * bestnb) % c);
  return 0;
}
