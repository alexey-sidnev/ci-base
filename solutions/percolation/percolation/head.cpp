#include "head.h"
#include <iostream>

using namespace std;
Sets::Sets(int _size) {
  if (_size < 0)
    throw std::exception("wrong size");
  size = _size;
  pr = new int[size];
  rank = new int[size];
  for (int i = 0; i < size; i++) {
    pr[i] = -1;
    rank[i] = -1;
  }
}

Sets::~Sets() {
  delete[]pr;
  delete[]rank;
}

void Sets::creat(int val) {
  if (val < 0 || val > size)
    throw std::exception("wrong index");
  if (pr[val] != -1)
    throw std::exception("wrong param");
  pr[val] = val;
  rank[val] = 0;
}

void Sets::merge(int n, int p) {
  if (n < 0 || n > size || p < 0 || p > size)
    throw std::exception("wrong index");
  if (pr[n] == -1 || pr[p] == -1)
    throw std::exception("wrong param");
  if (n != p) {
    int a = search(n);
    int b = search(p);
    if (a != b)
      if (rank[a] < rank[b])
        pr[a] = b;
      else {
        pr[b] = a;
        if (rank[a] == rank[b])
          ++rank[a];
      }
  }
}

int Sets::search(int val) {
  if (val < 0 || val > size)
    throw std::exception("wrong index");
  if (pr[val] == -1)
	  throw std::exception("wrong param");
  while (pr[val] != val)
    val = pr[val];
  return pr[val];
}

void Sets::clear() {
  for (int i = 0; i < size; i++) {
    pr[i] = -1;
    rank[i] = -1;
  }
}
