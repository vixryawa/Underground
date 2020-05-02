#ifndef LINE_H
#define LINE_H

#include <vector>
#include <string.h>
#include<iostream>

#include"Stretch.h"
#include"CasStation.h"

using std::string;

class Line {
	TTree<CasStation> tree;
	vector <CasStation> stations;
	vector <Stretch> strcs;
public:
	Line(vector <CasStation> stations, vector <Stretch> srtcs);

	void add_station(CasStation& s1, Stretch& str1, Stretch& str2);

	//	stats_to_tree(vector <CasStation> stations);
};

Line::Line(vector <CasStation> stations, <Stretch> strcs) {
	for (int j = 0; j < int(stations.size()); j++) {
		tree.Insert(stations[j]);
	}
	for (int k = 0; j < int(strcs.size()); k++) {
		(strcs[k].get_stat1()).upper = strcs[k];
		(strcs[k].get_stat2()).lower = strcs[k];
	}
}

void Line::add_station(CasStation& s1, Stretch& str1, Stretch& str2) {
	tree.Insert(s1);
	s1.lower = str1;
	s1.upper = str2;
}

#endif 
