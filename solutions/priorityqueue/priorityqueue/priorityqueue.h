#ifndef SOLUTIONS_PRIORITYQUEUE_PRIORITYQUEUE_PRIORITYQUEUE_H_
#define SOLUTIONS_PRIORITYQUEUE_PRIORITYQUEUE_PRIORITYQUEUE_H_

#include "dheap.h"

class PriorityQueue {
 protected:
  DAryHeap *heap;
 public:
  PriorityQueue(int d = 4);
  PriorityQueue(const PriorityQueue &queue);
  PriorityQueue(Data **keys, int num, int d = 4);
  ~PriorityQueue();

  void push(Data *&key);
  Data* pop();
  void refresh();
  int isFull();
  int isEmpty();
};

#endif  // SOLUTIONS_PRIORITYQUEUE_PRIORITYQUEUE_PRIORITYQUEUE_H_
