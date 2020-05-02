#ifndef LINE_H
#define LINE_H

#include <vector>
#include <string.h>
#include<iostream>

#include"Stretch.h"
#include"CasStation.h"
#include"TTree.h"

using std::string;

class Line {
	TTree<CasStation> tree;
	vector <CasStation> stations;
	vector <Stretch> strcs;
	vector <int> time;
	int count;
public:
	Line(vector <int> time);

	void add_station(CasStation& s1, int timeaway);

	int time_between(CasStation& s1, CasStation& s2);

	//	stats_to_tree(vector <CasStation> stations);
};

Line::Line(vector <int> time) {
	count = 0;
}

void Line::add_station(CasStation& s1, int timeaway) {
	tree.Insert(s1);
	time.push_back(timeaway);
	s1.n_added = count;
	count++;
}

int Line::time_between(CasStation& s1, CasStation& s2) {
	if (s1.n_added < s2.n_added)
		return time[s2.n_added] - time[s1.n_added];
	else
		return time[s1.n_added] - time[s2.n_added];
}

#endif 
