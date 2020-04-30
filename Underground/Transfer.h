#ifndef Transfer_H
#define Transfer_H

#include <string.h>
#include<iostream>
#include"CasStation.h"

using std::string;

class Transfer {
	CasStation st1;
	CasStation st2;
	int time;  // время на переход
	int traf; //пассариропоток
public:
	Transfer(const CasStation& st1, const CasStation& st2, int time, int traf)
		:st1(st1), st2(st2), time(time), traf(traf) {}

	void print() const;

	const CasStation& get_stat1();

	const CasStation& get_stat2();

	int get_time();

	int get_traf();

};

void Transfer::print() const {
	printf("Transfer is %i min long, traffic is %i and is between stations: ", this->time, this->traf);
	cout << this->st1 << " " << this->st2 << endl;
}

const CasStation& Transfer::get_stat1() {
	return this->st1;
}

const CasStation& Transfer::get_stat2() {
	return this->st2;
}

int Transfer::get_time() {
	return this->time;
}

int Transfer::get_traf() {
	return this->traf;
}
#endif 
