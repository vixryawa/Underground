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
    TNode<T>* l_child = nullptr;
    TNode<T>* r_child = nullptr;
    while (*cur) {
        TNode<T>& node = **cur;
        if (x < node.Key) {
            l_child = &node;
            cur = &node.Left;
            cur.Right = node;
            cur.rightThread = true;
            cur.leftThread = false;
            if (r_child)
            {
                cur.Left = &r_child;
                cur.leftThread = true;
            }

        }
        else if (x > node.Key) {
            r_child = &node;
            cur = &node.Right;
            node = &cur.Left;
            cur.rightThread = false;
            cur.leftThread = true;
            if (l_child)
            {
                cur.Right = &l_child;
                cur.rightThread = true;
            }
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
