#include "SearchTree.h"

void insert(node **root, node *s) {
  if (*root == 0) {
    *root = s;
    return;
  }
  node *a = *root;
  node *b = *root;
  while (a != 0) {
    b = a;
    if (s->key >= a->key)
      a = a->right;
    else
      a = a->left;
  }
  s->parent = b;
  if (s->key >= b->key)
    b->right = s;
  else
    b->left = s;
  return;
}

void Preorder(node *root, int *q) {
  if (root == NULL) {
    return;
  }
  int i = 0;
  std::stack <node*> st;
  while (!st.empty() || root != 0) {
    if (root != NULL) {
      std::cout << root->key << " ";
      q[i] = root->key;
      i++;
      if (root->right != 0) {
        st.push(root->right);
      }
      root = root->left;
    } else {
      root = st.top();
      st.pop();
    }
  }
}

void Inorder(node *root, int *q) {
  if (root == NULL) {
    return;
  }
  int i = 0;
  std::stack <node*> st;
  while (!st.empty() || root != 0) {
    if (root != 0) {
      st.push(root);
      root = root->left;
    } else {
      root = st.top();
      st.pop();
      std::cout << root->key << " ";
      q[i] = root->key;
      i++;
      root = root->right;
    }
  }
}

void Postorder(node *root, int *q) {
  if (root == NULL) {
    return;
  }
  node* lnp = 0;
  node* tmp = 0;
  int i = 0;
  std::stack <node*> st;
  while (!st.empty() || root != 0) {
    if (root != 0) {
      st.push(root);
      root = root->left;
    } else {
      tmp = st.top();
      if (tmp->right != 0 && lnp != tmp->right) {
        root = tmp->right;
      } else {
        st.pop();
        std::cout << tmp->key << " ";
        q[i] = tmp->key;
        i++;
        lnp = tmp;
      }
    }
  }
}

void init(node *n, int k) {
  n->key = k;
  n->left = 0;
  n->parent = 0;
  n->right = 0;
  return;
}
