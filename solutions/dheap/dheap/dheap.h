class heap {
 private:
  int size;
  int n;
  int *arr;
  int d;
 public:
  heap(int _size, int _d);
  ~heap();
  void swap(int i, int p);
  void up(int i);
  int min_child(int i);
  void down(int i);
  void hilling();
  int deletemin();
  void insert(int key);
};
