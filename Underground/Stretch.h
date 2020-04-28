#ifndef Stretch_H
#define Stretch_H

#include <string.h>
#include<iostream>

using std::string;

template <class T>
class Stretch {
	T st1; 
	T st2; 
	double time;  //! время прохождения перегона
public:
	Stretch(const T& s1, const T& s2, double time)
		:s1(s1), s2(s2), time(time);

	const T& get_stat1();

	const T& get_stat2();

	double get_time();

};

template <class T>


template <class T>
const T& Stretch<T>::get_stat1() {
	return this->st1;
}

template <class T>
const T& Stretch<T>::get_stat2() {
	return this->st2;
}

template <class T>
double Stretch<T>::get_time() {
	return this->time;
}
#endif 