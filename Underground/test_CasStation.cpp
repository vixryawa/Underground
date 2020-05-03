#include<cstdio>
#include<cassert>
#include<stdexcept>

#include"CasStation.h"
#include"TransStation.h"
#include"TNode.h"
#include"TTree.h"
#include"Stretch.h"
#include"Transfer.h"
#include"Line.h"



void test_CasStation() {

//проверка создания объектов классов Станций (обычных и пересадки)
    CasStation s1(4, 2000, "Vykhino");
    CasStation s2(6, 1500, "Kuzminki");
    TransStation s3(13, 10000, "Pushkinskaya");
    CasStation s5(7, 500, "Tekstilschiki");
    TransStation s4(1, 12000, "Chekchovskaya");

//проверка методов обычных станций
    assert(s1.get_n() == 4);
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
    // проверяем перегрузки операторов
    if (s1 > s2) {
        s2.print();
        s1.print();
    }
    else {
        s1.print();
        s2.print();
    }
    

//проверка методов станций пересадки
    s3.connect(s4);
    s4.connect(s3);
    Transfer transf1(s3, s4, 4, 11000);
    transf1.print();
    s3.print();
    s4.print();

//проверка работы прошитого бинарного дерева дерева
    TTree<CasStation> t1;
    //вставка
    t1.Insert(s2);
    t1.Insert(s3);
    t1.Insert(s1);
    t1.Insert(s5);
    t1.print_tree_();
    //найти ближайшие станции
    t1.find_neighbours(s5);
    

 //проверка класса перегона   
    Stretch strtch3(s5, s3, 3);
    Stretch strtch1(s2, s1, 2);
    Stretch strtch2(s5, s2, 4);

   //printf("%i\n", s2.get_upper());
    strtch1.print();
    
/*
// тестирую дерево для интов
    int b[] = { 10, 25, 20, 6, 21, 8, 1, 30 };
    TTree<int> t1;
    for (int i = 0; i < 8; i++) t1.Insert(b[i]);
    t1.print_tree_(); 
*/

//проверка класса линии
    Line line1;
    //добавляем станции с временем следования от начала ветки
    line1.add_station(s1, 0);
    line1.add_station(s2, 3);
    line1.add_station(s3, 10);
    line1.add_station(s5, 7);


    //проверка метода нахождения расстояния
    //printf("%i\n", line1.time_between(s2, s5));
    assert(line1.time_between(s2, s5) == 4);
    assert(line1.time_between(s1, s2) == 3);
    assert(line1.time_between(s1, s3) == 10);


}

int main() {
    test_CasStation();
    return 0;
}