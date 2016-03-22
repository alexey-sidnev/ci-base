#ifndef PERCOLATION_PERCOLATION_HEAD_H
#define PERCOLATION_PERCOLATION_HEAD_H

#pragma once

class Sets {
 public:
  int size; 
  int *pr;
  int *rank;

  Sets(int _size);
  ~Sets();
  void creat(int val);
  void merge(int n, int p);
  int search(int val);
  void clear();
};

#endif  // PERCOLATION_PERCOLATION_HEAD_H
