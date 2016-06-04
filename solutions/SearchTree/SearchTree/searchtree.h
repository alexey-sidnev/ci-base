#include <stack>
#include <iostream>

#ifndef SOLUTIONS_SEARCHTREE_SEARCHTREE_SEARCHTREE_H_
#define SOLUTIONS_SEARCHTREE_SEARCHTREE_SEARCHTREE_H_

struct node {
  int key;
  node *left;
  node *right;
  node *parent;
};

void insert(node **root, node *s);
void Preorder(node *root, int *q);
void Inorder(node *root, int *q);
void Postorder(node *n, int *q);
void init(node *n, int k);
void print(node *n);

#endif  // SOLUTIONS_SEARCHTREE_SEARCHTREE_SEARCHTREE_H_
