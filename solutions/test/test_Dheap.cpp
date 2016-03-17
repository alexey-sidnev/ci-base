#include "Dheap/Dheap.h"
#include <gtest/gtest.h>

TEST(heap, can_create_heap) {
  ASSERT_NO_THROW(Dheap(10, 3));
}

TEST(heap, cant_swap_with_wrong_index) {
  Dheap h(4, 2);
  h.keys[0] = 9;
  h.keys[1] = 1;
  h.keys[2] = 11;
  h.keys[3] = 18;
  ASSERT_ANY_THROW(h.Swap(-5, 3));
}

TEST(heap, can_swap) {
  Dheap h(4, 2);
  h.keys[0] = 9;
  h.keys[1] = 1;
  h.keys[2] = 11;
  h.keys[3] = 18;
  Dheap t(4, 2);
  t.keys[0] = 9;
  t.keys[1] = 11;
  t.keys[2] = 1;
  t.keys[3] = 18;
  h.Swap(1, 2);
  for (int i = 0; i < 4; i++)
    EXPECT_EQ(h.keys[i], t.keys[i]);
}

TEST(heap, can_find_minchild) {
  Dheap h(6, 2);
  h.keys[0] = 0;
  h.keys[1] = 2;
  h.keys[2] = 4;
  h.keys[3] = 8;
  h.keys[4] = 6;
  h.keys[5] = 7;
  EXPECT_EQ(h.MinChild(1), 4);
}

TEST(heap, can_sort_with_d2) {
  Dheap h(4, 2);
  h.keys[0] = 9;
  h.keys[1] = 1;
  h.keys[2] = 11;
  h.keys[3] = 18;
  h.Psort();
  int t[4] = {18, 11, 9, 1};
  for (int i = 0; i < 4; i++)
    EXPECT_EQ(h.keys[i], t[i]);
}

TEST(heap, can_sort_with_d3) {
  Dheap h(7, 3);
  h.keys[0] = 9;
  h.keys[1] = 1;
  h.keys[2] = 11;
  h.keys[3] = 18;
  h.keys[4] = 5;
  h.keys[5] = 7;
  h.keys[6] = 2;
  h.Psort();
  int t[7] = {18, 11, 9, 7, 5, 2, 1};
  for (int i = 0; i < 7; i++)
    EXPECT_EQ(h.keys[i], t[i]);
}

TEST(heap, can_down) {
  Dheap h(6, 2);
  h.keys[0] = 8;
  h.keys[1] = 0;
  h.keys[2] = 4;
  h.keys[3] = 2;
  h.keys[4] = 6;
  h.keys[5] = 7;
  Dheap t(6, 2);
  t.keys[0] = 0;
  t.keys[1] = 2;
  t.keys[2] = 4;
  t.keys[3] = 8;
  t.keys[4] = 6;
  t.keys[5] = 7;
  h.Down(0);
  for (int i = 0; i < 6; i++)
  EXPECT_EQ(h.keys[i], t.keys[i]);
}

TEST(heap, can_up) {
  Dheap h(6, 2);
  h.keys[0] = 1;
  h.keys[1] = 3;
  h.keys[2] = 4;
  h.keys[3] = 6;
  h.keys[4] = 0;
  h.keys[5] = 8;
  Dheap t(6, 2);
  t.keys[0] = 0;
  t.keys[1] = 1;
  t.keys[2] = 4;
  t.keys[3] = 6;
  t.keys[4] = 3;
  t.keys[5] = 8;
  h.Up(4);
  for (int i = 0; i < 6; i++)
  EXPECT_EQ(h.keys[i], t.keys[i]);
}
