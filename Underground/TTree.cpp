#include"TTree.h"
#include<iostream>
using namespace std;

void TTree::Insert(int x) {
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

void TTree::print_tree_() {
    print_tree(Root, 0);
}

void TTree::print_tree(TNode* p, int level) {
    if (p) {
        TTree::print_tree(p->Left, level + 1);
        for (int i = 0; i < level; i++) cout << "     ";
        cout << p->Key << endl;
        TTree::print_tree(p->Right, level + 1);
    }
}