#include "heap.h"

DHeap::DHeap(int n, int d) {
  N = n;
  A = new int[N];
  for (int i = 0; i < N; i++)
    A[i] = 0;
  D = d;
}

DHeap::~DHeap() {
  delete []A;
}

void DHeap::trans(int i, int j) {
  if ((i < 0) || (i > N) || (j < 0) || (j > N))
    throw exception("Wrong index");
  int tmp;
  tmp = A[i];
  A[i] = A[j];
  A[j] = tmp;
}

void DHeap::ascent(int i) {
  if ((i < 0) || (i > N))
    throw exception("Wrong index");
  int p = (i - 1) / D;
  while ((i != 0) && (A[p] > A[i])) {
    trans(i,p);
	i = p;
    p = (i - 1) / D;
  }
}

void DHeap::heaping() {
  for (int i = 0; i < N; i++) {
    ascent(i);
  }
}

int DHeap::minchild(int i) {
  if ((i < 0) || (i > N))
    throw exception("Wrong index");
  int p = i * D + 1;
  if (p > N - 1)
  return -1;
  else {
    int last = min ((i + 1) * D, N - 1);
    int minc = p;
    for (int j = p; j <= last; j++)
      if (A[minc] > A[j]) {
        minc = j;
	  }
  return minc;
  }
}

void DHeap::diving(int i) {
  if ((i < 0) || (i > N))
    throw exception("Wrong index");
  int tmp = minchild(i);
  while ((tmp != -1) && (A[tmp] < A[i])) {
    trans(tmp, i);
    i = tmp;
    tmp = minchild(i);
  }
}

void DHeap::sort() {
  heaping();
  while (N > 0)
  {
    trans(0, N - 1);
    N--;
    diving(0);
  }
}

bool DHeap::operator==(const DHeap &H1) {
  DHeap H1(N,D);
  for (int i = 0; i < N; 