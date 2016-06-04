#include "Sample.h"
#include "percolation.h"
#include <stdio.h>

void main() {
  int col = 150;
  int n = 10;
  int m = 10;
  int it = n*m + 2 * n;
  Sets A(it);
  double count;
  double result = 0;
  for (int i = 0; i < col; i++) {
    preparate(&A, n, m);
    count = 0;
    countn(&A, &count, n, m);
    result += count/ (n * m);
  }
  printf("%f\n", result / col);
}
