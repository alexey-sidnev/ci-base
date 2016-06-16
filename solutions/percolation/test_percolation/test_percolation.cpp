#include "percolation.h"
#include <gtest.h>

TEST(Sets, can_not_creat_set_with_negative_size) {
  ASSERT_ANY_THROW(Sets A(-5));
}

TEST(Sets, can_creat_set) {
  ASSERT_NO_THROW(Sets A(2));
}

TEST(Sets, can_add_node_in_set) {
  Sets A(3);
  ASSERT_NO_THROW(A.creat(2));
}

TEST(Sets, can_not_add_element_with_too_large_index_in_set) {
  Sets A(3);
  ASSERT_ANY_THROW(A.creat(13));
}

TEST(Sets, can_not_creat_node_which_creat_early) {
  Sets A(3);
  A.creat(2);
  ASSERT_ANY_THROW(A.creat(2));
}

TEST(Sets, can_merge_sets) {
  Sets A(4);
  A.creat(2);
  A.creat(3);
  ASSERT_NO_THROW(A.merge(2, 3));
}

TEST(Sets, can_not_merge_sets_which_one_of_two_sets_is_empty) {
  Sets A(4);
  A.creat(3);
  ASSERT_ANY_THROW(A.merge(1, 3));
}

TEST(Sets, can_not_search_element_with_negativ_index) {
  Sets A(2);
  ASSERT_ANY_THROW(A.search(-1));
}

TEST(Sets, can_search_element) {
  Sets A(3);
  A.creat(2);
  A.creat(1);
  ASSERT_NO_THROW(A.search(2));
}
