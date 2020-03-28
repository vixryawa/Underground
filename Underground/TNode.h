#ifndef TNODE_H
#define TNODE_H

template <class T>
class TNode {
public:

    T Key;

    TNode(T key): 
        Key(key), Left(0), Right(0) {}

    TNode* Left;
    TNode* Right;
}; 
/*
struct TNode {
    TNode* Left;
    TNode* Right;
    int Key;
}; */

#endif //TNODE_H