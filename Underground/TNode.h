#ifndef TNODE_H
#define TNODE_H

#include"CasStation.h"

class TNode {
public:

    CasStation Key;

    TNode(CasStation& Key):
        Key(Key), Left(0), Right(0) {}

    TNode* Left;
    TNode* Right;
    bool rightThread;
    bool leftThread;
}; 
/*
struct TNode {
    TNode* Left;
    TNode* Right;
    int Key;
}; */

#endif //TNODE_H