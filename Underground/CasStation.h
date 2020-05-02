#ifndef CASSTATION_H
#define CASSTATION_H

#include <string>
#include <iostream>
#include <vector>
//#include"Stretch.h"
using namespace std;

class CasStation {

public:
	int n; //!< ����� �� �����
	int traf; //!< ��������������
	string name; //!< �������� �������
	int upper_stretch = 0;
	//! �������� �������
	CasStation(int n = 0, int traf = 0, string name = "")
		:n(n), traf(traf), name(name) {}
	//! ��������� ������ �� �����
	int get_n() const {
		return n;
	}
	//! ��������� ���������������
	int get_traf() const {
		return traf;
	}
	//! ��������� ��������
	string get_name() const {
		return name;
	}
	//! ��������� ���������������
	bool set_traf(int NewTraf) {
		if (NewTraf >= 0) {
			traf = NewTraf;
			return true;
		}
		else
			return false;
	} 

	int get_upper();
	void add_upper(int time);

	//! ���������� ����������
	friend bool operator> (const CasStation &s1, const CasStation &s2);
	friend bool operator== (const CasStation &s1, const CasStation &s2);
	friend bool operator< (const CasStation& s1, const CasStation& s2);
	friend ostream& operator<<(ostream& os, const CasStation& cs);

	virtual void print() const;
	virtual ~CasStation() {}
};
#endif  