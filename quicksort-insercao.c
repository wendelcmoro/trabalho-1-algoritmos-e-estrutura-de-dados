#include "insercao.h"
#include "particiona.h"


/* -------------------------------------------------------------------------- */
/* ordena v[a..b] usando o algoritmo QuickSort com inser��o e devolve v       */

int *quicksort_insercao(int v[], int a, int b, unsigned int m) {
  int pos;

  if (b - a + 1 <= m) {
    insercao(v, a, b);
    return v;
  }
  pos = particiona(v, a, b, v[b]);
  v = quicksort_insercao(v, a, pos - 1, m);
  v = quicksort_insercao(v, pos + 1, b, m);
  return v;
}
