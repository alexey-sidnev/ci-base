#include <stdlib.h>
#include "percolation.h"
#include <ctime>

#ifndef SOLUTIONS_PERCOLATION_SAMPLE_SAMPLE_H_
#define SOLUTIONS_PERCOLATION_SAMPLE_SAMPLE_H_

void countn(Sets *A, double *count, int n, int m) {
  bool f = false;
  int x;
  int y;
  srand(666);
  int coord;
  while (f == false && (*count) < n*m) {
    do {
      x = rand() % n;
      y = rand() % m;
    } while ((*A).pr[x + (y + 1)*n] != -1);
    (*count)++;
    coord = x + (y + 1)*n;
    (*A).creat(coord);
    if (x != 0)
      if ((*A).pr[coord - 1] != -1)
        (*A).merge(coord, coord - 1);
    if ((*A).pr[coord - n] != -1)
      (*A).merge(coord, coord - n);
    if (x != n - 1)
      if ((*A).pr[coord + 1] != -1)
        (*A).merge(coord, coord + 1);
    if ((*A).pr[coord + n] != -1)
      (*A).merge(coord, coord + n);
    f = ((*A).search(0) == (*A).search((*A).size - 1));
  }
}

void preparate(Sets *A, int n, int m) {
  (*A).clear();
  for (int i = 0; i < n; i++) {
    (*A).creat(i);
    (*A).creat((*A).size - i - 1);
  }
  for (int i = 1; i < n; i++) {
    (*A).merge(0, i);
    (*A).merge((*A).size - 1, (*A).size - i - 1);
  }
}

#endif  // SOLUTIONS_PERCOLATION_SAMPLE_SAMPLE_H_
