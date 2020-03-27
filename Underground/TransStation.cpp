#include<cstdio>

#include"TransStation.h"

void TransStation::print() const {
    int j = 0;
    printf("Station %s is number %i and traffic is %i\nYou can change the line and go to %i stations: ",
        name.c_str(), n, traf, tnumber);
    for (j = 0; j < tnumber; j++) {
        printf("%s", transf[j].name.c_str());
    }
    printf("\n");
}

void TransStation::connect(TransStation &s2) {
    tnumber++;
    transf.push_back(s2);
}
    