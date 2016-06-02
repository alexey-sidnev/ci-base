#include "heap.h"

dheap :: dheap(int s, int dd) {
  size = s;
  arr = new int[size];
  for (int i = 0; i < size; i++)
    arr[i] = rand()%100;
  d = dd;
}

dheap :: ~dheap() {
  delete[]arr;
}

void dheap :: swap(int i, int j) {
  if ((i < 0)  || (j < 0) || (i > size) || (j > size))
    throw std::exception("wrong index");
  int tmp = arr[j];
  arr[j] = arr[i];
  arr[i] = tmp;
}

void dheap :: vspl(int i) {
  if ((i < 0)  || (i > size))
    throw std::exception("wrong index");
  int p = (i - 1) / d;
  while ((i != 0) && (arr[p] > arr[i])) {
    swap(i, p);
    i = p;
    p = (i - 1) / d;
  }
}

int dheap :: min(int i, int j) {
  int min = i;
  if (j < min)
    min = j;
  return min;
}

int dheap :: minchild(int i) {
  if ((i < 0)  || (i > size))
    throw std::exception("wrong index");
  int f = i * d + 1;
  if (f >= size)
    return -1;
  int l = min(i*d+d, size-1);
  int minc = f;
  for (int k = f+1; k <= l; k++) {
    if (arr[minc] > arr[k])
      minc = k;
  }
  return minc;
}

void dheap :: pogr(int i) {
  if ((i < 0)  || (i > size))
    throw std::exception("wrong index");
  int minc = minchild(i);
  while ((minc != -1) && (arr[minc] < arr[i])) {
    swap(minc, i);
    i = minc;
    minc = minchild(i);
  }
}

void dheap :: okuch() {
  int n = size;
  for (int i = n-1; i >=0; i--)
    pogr(i);
}

int dheap::delmin() {
  int min = arr[0];
  swap(size-1, 0);
  size--;
  okuch();
  return min;
}

void dheap::insert(int key) {
  arr[size] = key;
  vspl(size);
  size++;
}

void dheap :: sort() {
  okuch();
  int n = size;
  while (size > 0) {
    swap(0, size-1);
    size--;
    pogr(0);
  }
  size = n;
}

void dheap :: print() {
  for (int i = 0; i < size; i++)
    std::cout << arr[i] << ' ';
  std::cout << std::endl;
}
