#include "dheap.h"
#include <stdio.h>

heap::heap(int _size, int _d) {
  size = _size;
  d = _d;
  n = 0;
  arr = new int[size];
}

heap::~heap() {
  delete[]arr;
}

void heap::swap(int i, int p) {
  int tmp = arr[p];
  arr[p] = arr[i];
  arr[i] = tmp;
}

void heap::up(int i) {
  int p = (i - 1) / d;
  while (i != 0 && arr[p] > arr[i]) {
    swap(i, p);
    i = p;
    p = (i - 1) / d;
  }
}

int heap::min_child(int i) {
  int f = i * d + 1;
  if (f > n - 1)
    return 0;
  int l = n - 1;
  if ((i * d + d) < (n - 1))
    l = i * d + d;
  int min = f;
  for (int j = f; j <= l; j++)
    if (arr[min] > arr[j])
      min = j;
  return min;
}

void heap::down(int i) {
  int s = min_child(i);
  while (s != 0 && arr[i] > arr[s]) {
    swap(s, i);
    i = s;
    s = min_child(i);
  }
}

void heap::hilling() {
  for (int i = 0; i < n; i++)
    up(i);
}

int heap::deletemin() {
  int min = arr[0];
  swap(n - 1, 0);
  n = n - 1;
  hilling();
  return min;
}

void heap::insert(int key) {
  arr[n] = key;
  up(n);
  n++;
}
