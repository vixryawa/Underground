#include<cstdio>
#include<cassert>
#include<stdexcept>

#include"CasStation.h"
#include"TransStation.h"

void test_CasStation() {
    // создаём
    CasStation s1(1, 2000, "Vykhino");
    CasStation s2(2, 1500, "Kuzminki");
    TransStation s3(3, 10000, "Pushkinskaya", 0);
    TransStation s4(1, 12000, "Chekchovskaya", 0);

    s3.connect(s4);
    s4.connect(s3);

    assert(s1.get_n() == 1);
    assert(s1.get_traf() == 2000);
    // меняем пассажиропоток
    bool t;
    t = s1.set_traf(3000);
    assert(t);
    assert(s1.get_traf() == 3000);
    // меняем с ошибкой
    t = s1.set_traf(-5000);
    assert(!t);
    assert(s1.get_traf() == 3000);
    if (s1 > s2) {
        s2.print();
        s1.print();
    }
    else {
        s1.print();
        s2.print();
    }
    s3.print();
    s4.print();
}

int main() {
    test_CasStation();
    return 0;
}