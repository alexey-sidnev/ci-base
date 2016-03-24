#include <stack>
#include <iostream>	

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
