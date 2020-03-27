#ifndef TTREE_H
#define TTREE_H

#include"TNode.h"

class TTree {
public:
    TNode* Root;

    TTree(): Root(0){}

    ~TTree() {
        DestroyNode(Root);
    }

    static void DestroyNode(TNode* node) {
        if (node) {
            DestroyNode(node->Left);
            DestroyNode(node->Right);
            delete node;
        }
    }

    void Insert(int x);
    void print_tree_();
    void print_tree(TNode* p, int level);

};
#endif //TTREE_H