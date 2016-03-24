#ifndef SOLUTIONS_PERCOLATIONS_PERCOLATION_HEAD_H_
#define SOLUTIONS_PERCOLATIONS_PERCOLATION_HEAD_H_

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

#endif  // SOLUTIONS_PERCOLATIONS_PERCOLATION_HEAD_H_
