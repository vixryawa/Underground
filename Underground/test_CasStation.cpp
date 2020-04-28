#include<cstdio>
#include<cassert>
#include<stdexcept>

#include"CasStation.h"
#include"TransStation.h"
//#include"TNode.h"
//#include"TTree.h"
#include"Stretch.h"
#include"Transfer.h"

void test_CasStation() {
    // создаём
    CasStation s1(4, 2000, "Vykhino");
    CasStation s2(6, 1500, "Kuzminki");
    TransStation s3(13, 10000, "Pushkinskaya");
    CasStation s5(7, 500, "Tekstilschiki");
    TransStation s4(1, 12000, "Chekchovskaya");

    s3.connect(s4);
    s4.connect(s3);
    Transfer transf1(s3, s4, 4, 11000);
    transf1.print();

 /*   TTree<CasStation> t1;
    t1.Insert(s2);
    t1.Insert(s3);
    t1.Insert(s1);
    t1.Insert(s5);
    t1.print_tree_();
    */
    
    Stretch strtch1(s2, s5, 3);
    strtch1.print();


    /*
    // тестирую дерево для интов
    int b[] = { 10, 25, 20, 6, 21, 8, 1, 30 };
    TTree<int> t1;
    for (int i = 0; i < 8; i++) t1.Insert(b[i]);
    t1.print_tree_(); 



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
    assert(s1.get_traf() == 3000);*/
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