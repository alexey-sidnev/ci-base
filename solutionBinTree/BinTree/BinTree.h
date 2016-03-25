#ifndef SOLUTIONBINTREE_BINTREE_BINTREE_H_
#define SOLUTIONBINTREE_BINTREE_BINTREE_H_
#include <stack>
#include <iostream>

struct Node {
    int key;
    Node *left;
    Node *right;
    Node *parent;
};

void dirround(Node *n);
void revround(Node *n);
void simround(Node *n);

#endif  // SOLUTIONBINTREE_BINTREE_BINTREE_H_
