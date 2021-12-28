//
// Created by 肖应雄 on 2021/12/28.
//

#include <iostream>
using namespace std;
#include "3_2_2_mylist.h"
#include "3_2_4_myListIter.h"


int main325(){

    List<int> myList;

    for (int i = 0; i < 10; ++i) {
        myList.insert_front(i);
    }

    myList.display();

    ListIter<ListItem<int>> begin(myList.front());
}