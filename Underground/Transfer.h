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
public:
	Transfer(const CasStation& st1, const CasStation& st2, int time)
		:st1(st1), st2(st2), time(time) {}

	void print() const;

	const CasStation& get_stat1();

	const CasStation& get_stat2();

	int get_time();

};

void Transfer::print() const {
	printf("Transfer is %i min long and is between stations: ", this->time);
	cout << this->st1 << endl;
	cout << this->st2 << endl;
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
#endif 
