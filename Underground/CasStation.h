#ifndef CASSTATION_H
#define CASSTATION_H

#include <string>
#include <iostream>
using namespace std;

class CasStation {

public:
	int n; //!< номер на линии
	int traf; //!< пассажиропоток
	string name; //!< название станции
	//! создание станции
	CasStation(int n, int traf, string name)
		:n(n), traf(traf), name(name) {}
	//! получение номера на линии
	int get_n() const {
		return n;
	}
	//! получение пассажиропотока
	int get_traf() const {
		return traf;
	}
	//! получение названия
	string get_name() const {
		return name;
	}
	//! изменение пассажиропотока
	bool set_traf(int NewTraf) {
		if (NewTraf >= 0) {
			traf = NewTraf;
			return true;
		}
		else
			return false;
	} 
	//! перегрузка операторов
	friend bool operator> (const CasStation &s1, const CasStation &s2);
	friend bool operator== (const CasStation &s1, const CasStation &s2);
	friend bool operator< (const CasStation& s1, const CasStation& s2);
	friend ostream& operator<<(ostream& os, const CasStation& cs);

	virtual void print() const;
	virtual ~CasStation() {}
};
#endif  