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


//вставка нового узла
template <class T> 
void TTree<T>::Insert(T x){  
    TNode<T> cur = &Root;     //текущий узел для х
    TNode<T>* l_child = nullptr;     //последний предок имеющий левого потомка
    TNode<T>* r_child = nullptr;     //последний предок имеющий правого потомка
    while (*cur) { 
        TNode<T>& node = cur;         //рабочий узел относительно которого будем дальше двигать узел с х
        if (x < node.Key) {             //вставляем в левое поддерево
            l_child = &node;             //последний предок с левым потомком теперь это node
            cur = &node.Left;             //х - левый потомок node
            (cur)->Right = &node;             //прошивка для х
            (cur)->rightThread = true;             //теперь у х есть прошивка справа, указывает на родителя
            (cur)->leftThread = false;             //пока неизвестно про левую прошивку
            if (r_child) {                  //если был предок с правым потомком
                (cur)->Left = r_child;                //тогда у х есть левая прошивка,
                (cur)->leftThread = true;           // которая указывает на последнего предка с правым потомком
            } 
        } 
        else if (x > node.Key) { 
            r_child = &node;             
            cur = &node.Right;             
            (cur)->Left = &node;             
            (cur)->rightThread = false;             
            (cur)->leftThread = true;             
            if (l_child) { 
                (cur)->Right = l_child;                 
                (cur)->rightThread = true; 
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
