#ifndef TTREE_H
#define TTREE_H

#include<iostream>
using namespace std;

#include"TNode.h"

template <class T>
class TTree {
public:
    TNode<T> *Root;

    TTree(): Root(0){}

    ~TTree() {
        DestroyNode(Root);
    }

    static void DestroyNode(TNode<T> *node) {
        if (node) {
            DestroyNode(node->Left);
            DestroyNode(node->Right);
            delete node;
        }
    }

    void Insert(T x);
    void print_tree_();
    void print_tree(TNode<T> *p, int level);

};

template <class T>
void TTree<T>::Insert(T x) {
    TNode<T>** cur = &Root;
    while (*cur) {
        TNode<T>& node = **cur;
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
    *cur = new TNode<T>(x);
}

template <class T>
void TTree<T>::print_tree_() {
    print_tree(Root, 0);
}

template <class T>
void TTree<T>::print_tree(TNode<T>* p, int level) {
    if (p) {
        TTree<T>::print_tree(p->Left, level + 1);
        for (int i = 0; i < level; i++) printf("     ");
        cout << p->Key << endl;
        TTree<T>::print_tree(p->Right, level + 1);
    }
}

#endif //TTREE_H
