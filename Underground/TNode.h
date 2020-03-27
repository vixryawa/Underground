#ifndef TNODE_H
#define TNODE_H

class TNode {
public:
    int Key;

    TNode(int key): 
        Key(key), Left(0), Right(0) {}

    TNode* Left;
    TNode* Right;
};

#endif //TNODE_H