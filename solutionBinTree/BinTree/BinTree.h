#include <stack>
#include <iostream>

struct Node {
    int key;
    Node *left;
    Node *right;
	Node *parent;
};

void dirround (Node *n);
void revround(Node *n);
void simround(Node *n);