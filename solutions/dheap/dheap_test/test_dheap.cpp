#include "dheap.h"
#include <gtest.h>

TEST(dheap, can_up) {
  int _arr[2] = { 549, 8 };
  int _ar[2] = { 8, 549 };
  heap A(2, 3);
  for (int i = 0; i < 2; i++)
    A.insert(_arr[i]);
  for (int i = 0; i < 2; i++)
    _arr[i] = A.deletemin();
  int f = 1;
  for (int i = 0; i < 2; i++)
    if (_ar[i] != _arr[i]) {
      f = 0;
      break;
    }
  EXPECT_EQ(1, f);
}

TEST(dheap, can_find_minchild) {
  heap A(5, 2);
  A.insert(1);
  A.insert(3);
  A.insert(5);
  A.insert(7);
  A.insert(9);
  EXPECT_EQ(A.min_child(0), 1);
}

TEST(dheap, can_sort) {
  int _arr[8] = { 549, 8, 246, 2, 7, 98, 88, 1 };
  int _ar[8] = { 1, 2, 7, 8, 88, 98, 246, 549 };
  heap A(8, 2);
  for (int i = 0; i < 8; i++)
    A.insert(_arr[i]);
  for (int i = 0; i < 8; i++)
    _arr[i] = A.deletemin();
  int f = 1;
  for (int i = 0; i < 8; i++)
    if (_ar[i] != _arr[i]) {
      f = 0;
      break;
    }
  EXPECT_EQ(1, f);
}

TEST(dheap, can_swap) {
  int _arr[2] = { 549, 8 };
  int _ar[2];
  heap A(2, 3);
  for (int i = 0; i < 2; i++)
    A.insert(_arr[i]);
  A.swap(0, 1);
  for (int i = 0; i < 2; i++)
	  _ar[i] = A.deletemin();
  int f = 1;
  for (int i = 0; i < 2; i++)
    if (_arr[i] != _ar[i]) {
      f = 0;
      break;
    }
  EXPECT_EQ(1, f);
}

TEST(dheap, can_down) {
  int _arr[2] = { 549, 8 };
  int _ar[2] = { 8, 549 };
  heap A(2, 3);
  for (int i = 0; i < 2; i++)
    A.insert(_arr[i]);
  A.swap(0, 1);
  A.down(0);
  for (int i = 0; i < 2; i++)
	  _arr[i] = A.deletemin();
  int f = 1;
  for (int i = 0; i < 2; i++)
    if (_ar[i] != _arr[i]) {
      f = 0;
      break;
    }
  EXPECT_EQ(1, f);
}

