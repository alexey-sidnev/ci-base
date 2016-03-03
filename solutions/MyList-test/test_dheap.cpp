#include "head.h"
#include <gtest.h>

TEST(dheap, truesort) {
  int _arr[8] = { 549, 8, 246, 2, 7, 98, 88, 1 }; 
  int _ar[8] = { 1, 2, 7, 8, 88, 98, 246, 549 };
  heap A(8, 4);
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
