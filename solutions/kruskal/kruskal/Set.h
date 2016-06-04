#ifndef SOLUTIONS_KRUSKAL_KRUSKAL_SET_H_
#define SOLUTIONS_KRUSKAL_KRUSKAL_SET_H_

#pragma once

class Sets {
 public:
  int size;
  int *pr;

  explicit Sets(int _size);
  ~Sets();
  void creat(int val);
  void merge(int n, int p);
  int search(int val);
  void clear();
};

#endif  // SOLUTIONS_KRUSKAL_KRUSKAL_SET_H_
