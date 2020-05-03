#ifndef SUBWAY_H
#define SUBWAY_H

#include <vector>
#include <string.h>
#include<iostream>

#include"Transfer.h"
#include"CasStation.h"
#include"TTree.h"
#include"Line.h"

using std::string;
//создание класса метро
class Subway {
	vector <Line> lines; //! массив линий
	//vector <Transfer> transf;
	Transfer transfer[5][5]; //! массив пересадок
	int count; //! количество уже внесенных станций 
public:
	Subway();

	void add_line(Line& l1, Line& l2, Transfer &tr1);

	int time_between(CasStation& s1, CasStation& s2);
};

Subway::Subway() {

	count = 0;
}

//добавить станцию с временем следования от начала ветки
void Subway::add_line(Line& l1, Line& l2, Transfer& tr) {
	if (l1.number_ == -1) {
		lines.push_back(l1); // добавляем в контейнер 
		l1.number_ = count;
		count++;
	}
	if (l2.number_ == 0) {
		lines.push_back(l2); // добавляем в контейнер
		l2.number_ = count;
		count++;
	}
	transfer[l1.number_][l2.number_] = tr;
	transfer[l2.number_][l1.number_] = tr;
}

// найти расстояние (в минутах) между двумя станциями 
int Subway::time_between(CasStation& s1, CasStation& s2) {
	int x = -1;
	int y = -1;
	int k = 0;

	for (k = 0; k < int(lines.size()); k++)
		if ((lines[k].tree).Search_(s1))
			x = k;
	for (k = 0; k < int(lines.size()); k++)
		if ((lines[k].tree).Search_(s2))
			y = k;

	int r1 = lines[x].time_between((transfer[x][y]).get_stat1(), (transfer[x][y]).get_stat2());
	int r2 = lines[y].time_between((transfer[x][y]).get_stat1(), (transfer[x][y]).get_stat2());

	return r1 + r2 + (transfer[x][y]).get_time();
}

#endif 
