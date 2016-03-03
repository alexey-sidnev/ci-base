#ifndef GTEST_DHEAP_HEAD_H
#define GTEST_DHEAP_HEAD_H

class heap {
public:
  int size;
  int n;
  int *arr;
  int d;
  heap(int _size, int _d);
  ~heap();
  void swap(int i, int p);
  void up(int i);
  int min_child(int i);
  void down(int i);
  void hilling();
  int deletemin();
  void insert(int key);
  void print();
};

#endif  // GTEST_DHEAP_HEAD_H
