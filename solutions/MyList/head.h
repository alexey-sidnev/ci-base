#ifndef  SOLUTIONS_MYLIST_HEAD_H_
#define  SOLUTIONS_MYLIST_HEAD_H_

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

#endif  //  SOLUTIONS_MYLIST_HEAD_H_
