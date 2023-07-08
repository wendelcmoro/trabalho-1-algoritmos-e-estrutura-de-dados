#include "particiona.h"

/* -------------------------------------------------------------------------- */
/* ordena v[a..b] usando o algoritmo QuickSort e devolve v */

int *quicksort(int v[], int a, int b) {
  int m;

  if (a >= b) {
    return v;
  }
  m = particiona(v, a, b, v[b]);
  v = quicksort(v, a, m - 1);
  v = quicksort(v, m + 1, b);

  return v;
}
