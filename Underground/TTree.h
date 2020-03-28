#ifndef TTREE_H
#define TTREE_H

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
#endif //TTREE_H