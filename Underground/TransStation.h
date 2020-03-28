#ifndef STATION_H
#define STATION_H
#include <vector>

#include"CasStation.h"

//! описание
class TransStation : public CasStation {
    vector <TransStation> transf;

public:
    TransStation(int n, int traf, string name) :
        CasStation(n, traf, name) {}

    void connect(TransStation& s2);
    void print() const;
};
#endif  // STATION_H