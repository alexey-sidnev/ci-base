#ifndef SOLUTIONS_PERCOLATION_PERCOLATION_PERCOLATION_H_
#define SOLUTIONS_PERCOLATION_PERCOLATION_PERCOLATION_H_

#pragma once

class Sets {
 public:
  int size;
  int *pr;
  int *rank;

  explicit Sets(int _size);
  ~Sets();
  void creat(int val);
  void merge(int n, int p);
  int search(int val);
  void clear();
};

#endif  // SOLUTIONS_PERCOLATION_PERCOLATION_PERCOLATION_H_
