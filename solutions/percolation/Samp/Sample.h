#include <stdlib.h>
#include "head.h"
#include <ctime>

#ifndef PERCOLATION_SAMP_SAMPLE_H
#define PERCOLATION_SAMP_SAMPLE_H

void countn(Sets *a, int &count, int n, int m) {
  bool f = false;
  int x;
  int y;
  srand(time(NULL));
  int coord;
  while (f == false && count < n*m) {
    do {
      x = rand() % n;
      y = rand() % m;
    } while ((*a).pr[x + (y + 1)*n] != -1);
  count++;
  coord = x + (y + 1)*n;
  (*a).creat(coord);
  if (x != 0)
    if ((*a).pr[coord - 1] != -1)
      (*a).merge(coord, coord - 1);
  if ((*a).pr[coord - n] != -1)
    (*a).merge(coord, coord - n);
  if (x != n - 1)
  if ((*a).pr[coord + 1] != -1)
    (*a).merge(coord, coord + 1);
  if ((*a).pr[coord + n] != -1)
    (*a).merge(coord, coord + n);
  f = ((*a).search(0) == (*a).search((*a).size - 1));
  }
}

void preparate(Sets *a, int n, int m) {
  (*a).clear();
  for (int i = 0; i < n; i++) {
    (*a).creat(i);
    (*a).creat((*a).size - i - 1);
  }
  for (int i = 1; i < n; i++) {
    (*a).merge(0, i);
    (*a).merge((*a).size - 1, (*a).size - i - 1);
  }
}

#endif  // PERCOLATION_SAMP_SAMPLE_H
