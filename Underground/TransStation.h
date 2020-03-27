#ifndef STATION_H
#define STATION_H
#include <vector>

#include"CasStation.h"

//! описание
class TransStation : public CasStation {
    vector <TransStation> transf;
    int tnumber;//!< колво пересадок

public:
    TransStation(int n, int traf, string name, int tnumber) :
        CasStation(n, traf, name), tnumber(tnumber) {}

    void connect(TransStation& s2);
    void print() const;
};
#endif  // STATION_H