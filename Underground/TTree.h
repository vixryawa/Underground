#ifndef TTREE_H
#define TTREE_H

#include<iostream>
using namespace std;

#include"TNode.h"
#include"CasStation.h"

class TTree {
public:
	TNode* Root;

	TTree() : Root(0) {}

	~TTree() {
		DestroyNode(Root);
	}

	static void DestroyNode(TNode* node) {
		if (node) {
			if (!node->leftThread)
				DestroyNode(node->Left);
			if (!node->rightThread)
				DestroyNode(node->Right);
			delete node;
		}
	}

	void Insert(CasStation& x);
	void print_tree_();
	void print_tree(TNode* p, int level);
	void find_neighbours(CasStation& x);
	TNode* Search(CasStation& x, TNode* p);


};


//������� ������ ����
void TTree::Insert(CasStation& x) {
	// ��������� �� �� �����,
	// ���� ����� �������� ����� ����
	TNode** cur = &Root;
	// ����, ����� ����� � ������������ �����
	TNode* l_neighbour = nullptr;
	// ����, ����� ����� � ������������ ������
	TNode* r_neighbour = nullptr;

	while (true) {
		// ���� *cur==nullptr, �� ���� ���������
		// �������� � ���� � ��������.
		if (*cur == nullptr) {
			// ������ ����� ����
			*cur = new TNode(x);
			// ������ ��� ���� �������� � ������
			// �� ������, ���� ������ ��� ������� �� ������
			// ���� ������� ���� � �������� (��� �����)
			// ��� �������� (��� ������) ����������.
			if (l_neighbour != nullptr) {
				(*cur)->leftThread = true;
				(*cur)->Left = l_neighbour;
				// ���� � ����� ������ ���� ��������,
				// ���� ��������� � �� ������� ����
				if (l_neighbour->rightThread) {
					l_neighbour->Right = (*cur);
				}
			}
			if (r_neighbour != nullptr) {
				(*cur)->rightThread = true;
				(*cur)->Right = r_neighbour;
				if (r_neighbour->leftThread) {
					r_neighbour->Left = (*cur);
				}
			}
			return; // ������� ���������
		}

		// *curr!=nullptr, �.�. ������ �� � ����;
		// ���� ��� ���� ��������� � �����, �� �������
		if ((*cur)->Key == x)
			return; // ��������� ������ �� �����

		// ���� ���������, � ����� ��������� ������� ���������
		// ���� �����; ��� ���� ���� ������, ��� ���������
		// left � right ����� ���� ����������.
		if (x < (*cur)->Key) { // ���� ����� ���� ������ ��������,
			// �������� � ����� ����������.
			if ((*cur)->leftThread) {
				// ���� ����� --- ��������,
				// �� *cur --- ���� ������, � (*cur)->Left ---
				// ��� ����, ������� ������ x, �.�. ����� l_neighbour:
				l_neighbour = (*cur)->Left;
				r_neighbour = (*cur); // ������ ��� x ����� l_neighbour � cur
				(*cur)->leftThread = false; // ������ ��� �� ��������
				(*cur)->Left = nullptr; // ����� �� ��������� �������� ��������� �������
				cur = &((*cur)->Left); // ��������� � ��������� ��������
			}
			else {
				// ����� --- ����������, �� ��������. ����� ���������
				// �� ���, ����� ��� ���� r_neighbour
				r_neighbour = *cur;
				cur = &((*cur)->Left);
			}
		}
		else { // � ������ �� ��������� �����������
			if ((*cur)->rightThread) {
				r_neighbour = (*cur)->Right;
				l_neighbour = (*cur);
				(*cur)->rightThread = false;
				(*cur)->Right = nullptr;
				cur = &((*cur)->Right);
			}
			else {
				l_neighbour = *cur;
				cur = &((*cur)->Right);
			}
		}
	}
}


void TTree::print_tree_() {
	print_tree(Root, 0);
}

void TTree::print_tree(TNode* p, int level) {
	if (p) {
		if (!p->leftThread)
			TTree::print_tree(p->Left, level + 1);
		for (int i = 0; i < level; i++) printf("     ");
		cout << p->Key << endl;
		if (!p->rightThread)
			TTree::print_tree(p->Right, level + 1);
	}
}

//!������� ������ ������� � ������
TNode* TTree::Search(CasStation& x, TNode* p) {
	if ((p->Key == x) || (p == nullptr)) {  //!���� �����, �� ���������� ������ ����
		//cout << p->Key << endl;
		return p;
	}
	if ((x < p->Key) && (p->leftThread == false)) //! ���� �������� ������, �� �������� ����� � ����� ��������� 
		return TTree::Search(x, p->Left);
	if ((x > p->Key) && (p->rightThread == false))				//! ���� �������� ������, �� �������� ����� � ������ ��������� 
		return TTree::Search(x, p->Right);
}

//������� ������ ��������� �������
void TTree::find_neighbours(CasStation& x) {
	TNode* p = Search(x, Root); //������� ������ ���� ������������� ������ �������
	cout << "Staions closest to the station " << p->Key; 
	cout << " are " << (p->Left)->Key;
	cout << " and " << (p->Right)->Key << endl;
	cout << "Mins away: " << ((p->Left)->Key).get_upper() << " " << (p->Key).get_upper() << endl;
}


#endif //TTREE_H
