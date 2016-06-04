#include "SearchTree.h"
#include <gtest.h>

TEST(SearchTree, can_insert_node) {
  node root, a;
  init(&root, 6);
  init(&a, 2);
  node *A = &root;
  ASSERT_NO_THROW(insert(&A, &a));
}

TEST(SearchTree, can_do_Preorder) {
  node root, a, b, c, d, e, f, g, h;
  int q[9];
  int eq[] = { 6, 2, 0, 1, 4, 5, 8, 7, 9 };
  init(&root, 6);
  init(&a, 2);
  init(&b, 8);
  init(&c, 0);
  init(&d, 4);
  init(&e, 7);
  init(&f, 9);
  init(&g, 1);
  init(&h, 5);
  node *A = &root;
  insert(&A, &a);
  insert(&A, &b);
  insert(&A, &c);
  insert(&A, &d);
  insert(&A, &e);
  insert(&A, &f);
  insert(&A, &g);
  insert(&A, &h);
  Preorder(A, q);
  int z = 0;
  for (int i = 0; i < 9; i++)
    if (q[i] != eq[i]) {
      z = 1;
      break;
    }
  EXPECT_EQ(0, z);
}

TEST(SearchTree, can_do_Inorder) {
  node root, a, b, c, d, e, f, g, h;
  int q[9];
  int eq[] = { 0, 1, 2, 4, 5, 6, 7, 8, 9 };
  init(&root, 6);
  init(&a, 2);
  init(&b, 8);
  init(&c, 0);
  init(&d, 4);
  init(&e, 7);
  init(&f, 9);
  init(&g, 1);
  init(&h, 5);
  node *A = &root;
  insert(&A, &a);
  insert(&A, &b);
  insert(&A, &c);
  insert(&A, &d);
  insert(&A, &e);
  insert(&A, &f);
  insert(&A, &g);
  insert(&A, &h);
  Inorder(A, q);
  int z = 0;
  for (int i = 0; i < 9; i++)
    if (q[i] != eq[i]) {
      z = 1;
      break;
    }
  EXPECT_EQ(0, z);
}

TEST(SearchTree, can_do_Postorder) {
  node root, a, b, c, d, e, f, g, h;
  int q[9];
  int eq[] = { 1, 0, 5, 4, 2, 7, 9, 8, 6 };
  init(&root, 6);
  init(&a, 2);
  init(&b, 8);
  init(&c, 0);
  init(&d, 4);
  init(&e, 7);
  init(&f, 9);
  init(&g, 1);
  init(&h, 5);
  node *A = &root;
  insert(&A, &a);
  insert(&A, &b);
  insert(&A, &c);
  insert(&A, &d);
  insert(&A, &e);
  insert(&A, &f);
  insert(&A, &g);
  insert(&A, &h);
  Postorder(A, q);
  int z = 0;
  for (int i = 0; i < 9; i++)
    if (q[i] != eq[i]) {
      z = 1;
      break;
    }
  EXPECT_EQ(0, z);
}
