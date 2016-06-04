#include "searchtree.h"
#include "stdio.h"

void main() {
  node root, a, b, c, d, e, f, g, h;
  int q[9];
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
  printf("\n");
  Inorder(A, q);
  printf("\n");
  Postorder(A, q);
  printf("\n");
  return;
}
