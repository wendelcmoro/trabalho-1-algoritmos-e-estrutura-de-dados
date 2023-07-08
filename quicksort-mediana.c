#include "particiona.h"
#include "biblioteca.h"

/* -------------------------------------------------------------------------- */
/* devolve a mediana de a, b e c                                              */

static int mediana(int a, int b, int c) {
  if ((0 <= compara(a, b) && 0 >= compara(a, c)) ||
      (0 >= compara(a, b) && 0 <= compara(a, c))) {
    return a;
  }
  if ((0 <= compara(b, a) && 0 >= compara(b, c)) ||
      (0 >= compara(b, a) && 0 <= compara(b, c))) {
    return b;
  }
  return c;
}

/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
/* ordena v[a..b]  usando o algoritmo  "QuickSort com mediana de  3" e
   devolve v                                                                  */

int *quicksort_mediana(int v[], int a, int b) {
  int m, medi, vIndices[3];
  if (b <= a) {
    return v;
  }
  for (int i = 0; i < 3; i++) {
    vIndices[i] = sorteia(a, b);
  }
  medi = mediana(v[vIndices[0]], v[vIndices[1]], v[vIndices[2]]);
  for (int i = 0; i < 3; i++) {
    if (0 == compara(v[vIndices[i]], medi)) {
      troca(v, vIndices[i], b);
			break;
    }
  }
  //printf("(%d)", medi);
  m = particiona(v, a, b, medi);
  v = quicksort_mediana(v, a, m - 1);
  v = quicksort_mediana(v, m + 1, b);

  return v;
}
