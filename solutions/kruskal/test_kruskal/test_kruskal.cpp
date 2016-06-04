#include "Set.h"
#include <gtest.h>

TEST(Sets, can_create_Sets) {
  EXPECT_NO_THROW(Sets A(7));
}

TEST(Sets, cant_create_singleton_with_large_index) {
  Sets A(7);
  EXPECT_ANY_THROW(A.creat(8));
}

TEST(Sets, can_create_singleton) {
  Sets A(7);
  A.creat(1);
  EXPECT_EQ(A.pr[1], 1);
}

TEST(Sets, can_search) {
  Sets A(7);
  A.creat(1);
  A.creat(0);
  A.creat(2);
  A.merge(1, 2);
  A.merge(2, 0);
  EXPECT_EQ(A.search(1), 0);
}
TEST(Sets, can_merge) {
  Sets A(7);
  A.creat(1);
  A.creat(0);
  A.creat(2);
  A.merge(1, 2);
  A.merge(0, 1);
  EXPECT_EQ(A.pr[0], 2);
}
