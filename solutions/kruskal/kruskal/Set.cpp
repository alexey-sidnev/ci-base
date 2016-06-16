#include "Set.h"

Sets::Sets(int _size) {
  if (_size < 0)
    throw "wrong size";
  size = _size;
  pr = new int[size];
  for (int i = 0; i < size; i++)
    pr[i] = -1;
}

Sets::~Sets() {
  delete[]pr;
}

void Sets::creat(int val) {
  if (val < 0 || val > size)
    throw "wrong index";
  if (pr[val] != -1)
    throw "wrong param";
  pr[val] = val;
}

void Sets::merge(int n, int p) {
  if (n < 0 || n > size || p < 0 || p > size)
    throw "wrong index";
  if (pr[n] == -1 || pr[p] == -1)
    throw "wrong param";
  if (n != p) {
    int a = n;
    int b = p;
    while (pr[a] != a)
      a = pr[a];
    while (pr[b] != b)
      b = pr[b];
    if (a != b)
      pr[a] = b;
  }
}

int Sets::search(int val) {
  if (val < 0 || val > size)
    throw "wrong index";
  if (pr[val] == -1)
    throw "wrong param";
  while (pr[val] != val)
    val = pr[val];
  return pr[val];
}

void Sets::clear() {
  for (int i = 0; i < size; i++)
    pr[i] = -1;
}
