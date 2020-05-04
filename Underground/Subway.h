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
	//vector <Transfer> transfers;
	// Transfer transfer[5][5]; //! массив пересадок
	int count; //! количество уже внесенных станций 
public:
	Subway();

	void add_line(Line& l1);

	void add_transf(Line& l1, Line& l2, Transfer& tr);

	void add_stat_to_line(CasStation& s, int timeaway, Line& l);

	//int time_between(CasStation& s1, CasStation& s2);
};

Subway::Subway() {

	count = 0;
}

void Subway::add_line(Line& l1) {
	lines.push_back(l1);
}

void Subway::add_transf(Line& l1, Line& l2, Transfer& tr) {
	//transfers.push_back(tr);
	(l1.transf).push_back(tr);
	(l2.transf).push_back(tr);
}

void Subway::add_stat_to_line(CasStation& s, int timeaway, Line& l) {
	l.add_station(s, timeaway);
}

/*
// найти расстояние (в минутах) между двумя станциями 
int Subway::time_between(CasStation& s1, CasStation& s2) {
	int x = -1;
	int y = -1;
	int k = 0;
	int m = 0;
	int r3 = 0;
	Transfer tr;

	for (k = 0; k < int(lines.size()); k++)
		if ((lines[k].tree).Search_(s1))
			x = k;
	for (k = 0; k < int(lines.size()); k++)
		if ((lines[k].tree).Search_(s2))
			y = k;

	/*for (k = 0; k < int((lines[x].transf).size()); k++)
		for (m = 0; m < int((lines[y].transf).size()); m++)
			if ((lines[x]).transf[k] == (lines[y]).transf[m]) {
				r3 = ((lines[x]).transf[k]).get_time();
				tr = (lines[x]).transf[k];
			}
			
	int r1 = lines[x].time_between(tr.get_stat1(), tr.get_stat2());
	int r2 = lines[y].time_between(tr.get_stat1(), tr.get_stat2());

	return r1 + r2 + r3;
}
*/
#endif 
