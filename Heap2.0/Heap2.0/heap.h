#pragma once
#include <iostream>

using namespace std;

class DHeap {
 public:
  int *A;
  int N;
  int D;
 public:
  DHeap();
  DHeap(int n, int d);
  ~DHeap();
  void trans(int i, int j);
  void ascent(int i);
  void heaping();
  int minchild(int i);
  void diving(int i);
  void sort();
  bool operator==(const DHeap &);
};