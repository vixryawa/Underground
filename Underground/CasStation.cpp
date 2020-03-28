#include<cstdio>
#include <iostream>
using namespace std;

#include"CasStation.h"

void CasStation::print() const {
    printf("Station %s is number %i and traffic is %i\n",
        name.c_str(), n, traf);
}

bool operator> (const CasStation& s1, const CasStation& s2)
{
    return s1.n > s2.n;
}

bool operator== (const CasStation& s1, const CasStation& s2)
{
    return s1.n == s2.n;
}

bool operator< (const CasStation& s1, const CasStation& s2)
{
    return !(s1 == s2 || s1 > s2);
}

ostream& operator<<(ostream& os, const CasStation& a)
{
    os << a.name;
    return os;
}
