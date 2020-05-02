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


//вставка нового узла
void TTree::Insert(CasStation& x) {
	// указатель на то место,
	// куда будет вставлен новый узел
	TNode** cur = &Root;
	// узел, ближе всего к вставляемому снизу
	TNode* l_neighbour = nullptr;
	// узел, ближе всего к вставляемому сверху
	TNode* r_neighbour = nullptr;

	while (true) {
		// если *cur==nullptr, то надо вставлять
		// значение в узел и выходить.
		if (*cur == nullptr) {
			// создаём новый узел
			*cur = new TNode(x);
			// создаём для него прошивки с каждой
			// из сторон, если раньше при проходе по дереву
			// были найдены узлы с меньшими (для левой)
			// или большими (для правой) значениями.
			if (l_neighbour != nullptr) {
				(*cur)->leftThread = true;
				(*cur)->Left = l_neighbour;
				// если у этого соседа есть прошивка,
				// надо поместить в неё текущий узел
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
			return; // вставка завершена
		}

		// *curr!=nullptr, т.е. сейчас мы в узле;
		// если его ключ совпадает с нашим, то выходим
		if ((*cur)->Key == x)
			return; // вставлять ничего не будем

		// надо проверить, в какое поддерево следует перевести
		// цикл далее; при этом надо учесть, что указатели
		// left и right могут быть прошивками.
		if (x < (*cur)->Key) { // если новый ключ меньше текущего,
			// работаем с левым поддеревом.
			if ((*cur)->leftThread) {
				// если связь --- прошивка,
				// то *cur --- лист дерева, а (*cur)->Left ---
				// тот узел, который меньше x, т.е. новый l_neighbour:
				l_neighbour = (*cur)->Left;
				r_neighbour = (*cur); // потому что x между l_neighbour и cur
				(*cur)->leftThread = false; // теперь это не прошивка
				(*cur)->Left = nullptr; // чтобы на следующей итерации произошла вставка
				cur = &((*cur)->Left); // переходим к следующей итерации
			}
			else {
				// связь --- нормальная, не прошивка. Тогда переходим
				// по ней, меняя при этом r_neighbour
				r_neighbour = *cur;
				cur = &((*cur)->Left);
			}
		}
		else { // с правым всё зеркально симметрично
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

//!функция поиска станции в дереве
TNode* TTree::Search(CasStation& x, TNode* p) {
	if ((p->Key == x) || (p == nullptr)) {  //!если нашли, то возвращаем нужный узел
		//cout << p->Key << endl;
		return p;
	}
	if ((x < p->Key) && (p->leftThread == false)) //! если значение меньше, то вызываем поиск в левом поддереве 
		return TTree::Search(x, p->Left);
	if ((x > p->Key) && (p->rightThread == false))				//! если значение больше, то вызываем поиск в правом поддереве 
		return TTree::Search(x, p->Right);
}

//функция поиска ближайших соседей
void TTree::find_neighbours(CasStation& x) {
	TNode* p = Search(x, Root); //находим какому узлу соответствует нужная станция
	cout << "Staions closest to the station " << p->Key; 
	cout << " are " << (p->Left)->Key;
	cout << " and " << (p->Right)->Key << endl;
	cout << "Mins away: " << ((p->Left)->Key).get_upper() << " " << (p->Key).get_upper() << endl;
}


#endif //TTREE_H
