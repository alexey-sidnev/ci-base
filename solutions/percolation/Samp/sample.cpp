#include "Sample.h"
#include "head.h"
#include <stdio.h>

void main() {
  int col = 100;
  int n = 3;
  int m = 3;
  int it = n*m + 2 * n;
  Sets A(it);
  int count;
  double result = 0;
  for (int i = 0; i < col; i++) {
    preparate(&A, n, m);
    count = 0;
    countn(&A, count, n, m);
    result += count*1.0 / n / m;
  }
  printf("percentage = %f\n", result / col);
}
