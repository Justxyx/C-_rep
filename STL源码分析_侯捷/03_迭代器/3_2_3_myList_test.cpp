//
// Created by 肖应雄 on 2021/12/27.
//


#include <iostream>
using namespace std;
#include "3_2_2_mylist.h"


int main(){
    List<int> l;
    for (int i = 0; i < 10; ++i) {
        l.insert_front(i);
    }
    l.display();
}