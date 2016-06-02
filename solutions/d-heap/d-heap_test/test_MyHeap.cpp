#include "heap.h"
#include <gtest.h>

TEST(heap, Can_swap) {
  dheap h(3, 2);
  h.arr[0] = 2;
  h.arr[1] = 7;
  h.arr[2] = 5;
  dheap h1(3, 2);
  h1.arr[0] = 7;
  h1.arr[1] = 2;
  h1.arr[2] = 5;
  h.swap(0, 1);
  for (int i = 0; i < 3; i++)
    EXPECT_EQ(h.arr[i], h1.arr[i]);
}

TEST(heap, minchild_test) {
  dheap h(5, 2);
  h.arr[1] = 0;
  h.arr[2] = 3;
  EXPECT_EQ(h.minchild(0), 1);
}

TEST(heap, cant_down_with_wrong_idx) {
  dheap h(5, 2);
  ASSERT_ANY_THROW(h.vspl(-1));
}

TEST(heap, sorts_d_2) {
  dheap h(5, 2);
  h.arr[0] = 4;
  h.arr[1] = 17;
  h.arr[2] = 0;
  h.arr[3] = 12;
  h.arr[4] = 1;
  h.sort();
  h.print();
  int h1[5] = {17, 12, 4, 1, 0};
  for (int i = 0; i < 5; i++)
    EXPECT_EQ(h.arr[i], h1[i]);
}

TEST(heap, sorts_d_3) {
  dheap h(5, 3);
  h.arr[0] = 4;
  h.arr[1] = 17;
  h.arr[2] = 0;
  h.arr[3] = 12;
  h.arr[4] = 1;
  h.sort();
  h.print();
  int h1[5] = {17, 12, 4, 1, 0};
  for (int i = 0; i < 5; i++)
    EXPECT_EQ(h.arr[i], h1[i]);
}

TEST(heap, Can_down) {
  dheap h(6, 2);
  h.arr[0] = 10;
  h.arr[1] = 0;
  h.arr[2] = 5;
  h.arr[3] = 3;
  h.arr[4] = 11;
  h.arr[5] = 0;
  dheap h1(6, 2);
  h1.arr[0] = 0;
  h1.arr[1] = 3;
  h1.arr[2] = 5;
  h1.arr[3] = 10;
  h1.arr[4] = 11;
  h1.arr[5] = 0;
  h.pogr(0);
  for (int i = 0; i < 6; i++)
  EXPECT_EQ(h.arr[i], h1.arr[i]);
}

TEST(heap, Can_up) {
  dheap h(6, 2);
  h.arr[0] = 10;
  h.arr[1] = 0;
  h.arr[2] = 5;
  h.arr[3] = 3;
  h.arr[4] = 11;
  h.arr[5] = 0;
  dheap h1(6, 2);
  h1.arr[0] = 0;
  h1.arr[1] = 0;
  h1.arr[2] = 10;
  h1.arr[3] = 3;
  h1.arr[4] = 11;
  h1.arr[5] = 5;
  h.vspl(5);
  h.print();
  h1.print();
  for (int i = 0; i < 6; i++)
  EXPECT_EQ(h.arr[i], h1.arr[i]);
}
