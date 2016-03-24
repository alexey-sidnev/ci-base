#ifndef SOLUTIONS_DHEAP_DHEAP_H_
#define SOLUTIONS_DHEAP_DHEAP_H_
#include <iostream>

class Dheap {
 public:
    int d;
    int size;
    int *keys;
    Dheap(int _s, int _d);
    ~Dheap();
    void Swap(int i, int j);
    void Up(int i);
    void Down(int i);
    int min(int n, int m);
    int MinChild(int i);
    void DoHeap();
    void Psort();
};
#endif  // SOLUTIONS_DHEAP_DHEAP_H_
