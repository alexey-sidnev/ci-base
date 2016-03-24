#include "BinTree.h"

void dirround(Node *n) {
    std::stack<Node*> st;
    st.push(n);
    while (!st.empty()) {
        Node *tmp = st.top();
        st.pop();
        std::cout<<tmp->key<<" ";
        if (tmp->right != 0)
            st.push(tmp->right);
        if (tmp->left != 0)
            st.push(tmp->left);
    }
    std::cout << std::endl;
}

void revround(Node *n) {
    std::stack <Node*> st;
    Node *tmp = n;
    Node *tmp1 = 0;
    Node *tmp2 = 0;
    while (!st.empty() || tmp != 0) {
        if (tmp != 0) {
            st.push(tmp);
            tmp = tmp->left;
        } else {
            tmp1 = st.top();
            if (tmp1->right != 0 && tmp2 != tmp1->right) {
                tmp = tmp1->right;
            } else {
                st.pop();
                std::cout << tmp1->key << " ";
                tmp2 = tmp1;
            }
        }
    }
    std::cout << std::endl;
}

void simround(Node *n) {
    std::stack <Node*> st;
    Node *tmp = n;
    while (!st.empty() || tmp != 0) {
        if (tmp != 0) {
            st.push(tmp);
            tmp = tmp->left;
        } else {
            tmp = st.top();
            st.pop();
            std::cout << tmp->key << " ";
            tmp = tmp->right;
        }
    }
    std::cout << std::endl;
}
