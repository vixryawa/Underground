#ifndef LINE_H
#define LINE_H

#include <vector>
#include <string.h>
#include<iostream>

#include"Stretch.h"
#include"CasStation.h"
#include"TTree.h"

using std::string;
//!создание класса линия
class Line {
	TTree<CasStation> tree; //! дерево для хранения станций
	//vector <CasStation> stations;
	//vector <Stretch> strcs;
	vector <int> time; //! массив расстояний станций от начала ветки
	int count; //! количество уже внесенных станций 
public:
	Line();

	void add_station(CasStation& s1, int timeaway);

	int time_between(CasStation& s1, CasStation& s2);

	//stats_to_tree(vector <CasStation> stations);
};

Line::Line() {
	count = 0;
}

//добавить станцию с временем следования от начала ветки
void Line::add_station(CasStation& s1, int timeaway) {
	tree.Insert(s1); // вставляем в дерево
	time.push_back(timeaway); // добавляем в контейнер расстояний время
	s1.n_added = count; // запоминаем для каждой станции какой по счету она добавлена 
	count++; // количество уже внесенных станций увеличивается
}

// найти расстояние (в минутах) между двумя станциями на ветке
int Line::time_between(CasStation& s1, CasStation& s2) {
	if (s1.n_added < s2.n_added)
		return time[s2.n_added] - time[s1.n_added];
	else
		return time[s1.n_added] - time[s2.n_added];
}

#endif 
