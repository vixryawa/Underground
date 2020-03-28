#include"TTree.h"
#include<iostream>
using namespace std;

template <class T>
void TTree<T>::Insert(T x) {
    TNode** cur = &Root;
    while (*cur) {
        TNode& node = **cur;
        if (x < node.Key) {
            cur = &node.Left;
        }
        else if (x > node.Key) {
            cur = &node.Right;
        }
        else {
            return;
        }
    }
    *cur = new TNode(x);
}

template <class T>
void TTree<T>::print_tree_() {
    print_tree(Root, 0);
}

template <class T>
void TTree<T>::print_tree(TNode<T> *p, int level) {
    if (p) {
        TTree<T>::print_tree(p->Left, level + 1);
        for (int i = 0; i < level; i++) cout << "     ";
        cout << p->Key << endl;
        TTree<T>::print_tree(p->Right, level + 1);
    }
}