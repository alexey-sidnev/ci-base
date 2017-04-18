#include "heap.h"
#include <gtest.h>

TEST(heap, Can_trans) {
  DHeap H(5, 2);
  H.A[0] = 2;
  H.A[2] = 7;
  H.A[4] = 5;
  DHeap H1(5, 2);
  H1.A[0] = 5;
  H1.A[2] = 7;
  H1.A[4] = 2;
  H.trans(0,4);
  EXPECT_EQ(H.A, H1,A);
}

TEST(heap, Cant_trans_with_wrong_index) {
  DHeap H(5, 2);
  H.A[0] = 2;
  H.A[2] = 7;
  H.A[4] = 5;
  ASSERT_ANY_THROW(H.trans(-1,4));
}

TEST(heap, Cant_ascent_with_wrong_index) {
  DHeap H(5, 2);
  H.A[0] = 2;
  H.A[2] = 7;
  H.A[4] = 5;
  ASSERT_ANY_THROW(H.ascent(-10));
}

TEST(heap, Can_ascent) {
  DHeap H(7, 2);
  H.A[0] = 2;
  H.A[1] = 6;
  H.A[2] = 7;
  H.A[3] = 9;
  H.A[4] = 1;
  H.A[5] = 8;
  H.A[6] = 9;
  DHeap H1(7, 2);
  H1.A[0] = 1;
  H1.A[1] = 2;
  H1.A[2] = 7;
  H1.A[3] = 9;
  H1.A[4] = 6;
  H1.A[5] = 8;
  H1.A[6] = 9;
  H.ascent(4);
  EXPECT_EQ(H.A, H1.A);
}

TEST(heap, Cant_minchild_with_wrong_index) {
  DHeap H(5, 2);
  H.A[0] = 2;
  H.A[2] = 7;
  H.A[4] = 5;
  ASSERT_ANY_THROW(H.minchild(-10));
}

TEST(heap, Can_minchild) {
  DHeap H(7, 2);
  H.A[0] = 2;
  H.A[1] = 6;
  H.A[2] = 7;
  H.A[3] = 9;
  H.A[4] = 1;
  H.A[5] = 8;
  H.A[6] = 9;
  EXPECT_EQ(6, H.minchild(0));
}

TEST(heap, Can_diving) {
  DHeap H(7, 2);
  H.A[0] = 10;
  H.A[1] = 6;
  H.A[2] = 7;
  H.A[3] = 9;
  H.A[4] = 1;
  H.A[5] = 8;
  H.A[6] = 9;
  DHeap H1(7, 2);
  H1.A[0] = 6;
  H1.A[1] = 1;
  H1.A[2] = 7;
  H1.A[3] = 9;
  H1.A[4] = 10;
  H1.A[5] = 8;
  H1.A[6] = 9;
  H.diving(0);
  EXPECT_EQ(H.A, H1.A);
}

TEST(heap, Cant_diving_with_wrong_index) {
  DHeap H(5, 2);
  H.A[0] = 2;
  H.A[2] = 7;
  H.A[4] = 5;
  ASSERT_ANY_THROW(H.diving(-10));
}

TEST(heap, Can_sort) {
  DHeap H(7, 2);
  H.A[0] = 10;
  H.A[1] = 6;
  H.A[2] = 7;
  H.A[3] = 9;
  H.A[4] = 1;
  H.A[5] = 8;
  H.A[6] = 9;
  DHeap H1(7, 2);
  H1.A[0] = 10;
  H1.A[1] = 9;
  H1.A[2] = 9;
  H1.A[3] = 8;
  H1.A[4] = 7;
  H1.A[5] = 6;
  H1.A[6] = 1;
  H.sort();
  EXPECT_EQ(H.A, H1.A);
}