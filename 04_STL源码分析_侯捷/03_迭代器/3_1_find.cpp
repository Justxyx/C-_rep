//
// Created by 肖应雄 on 2021/12/27.
//
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;

int  main3_1(){
    const int arraySize = 7;
    int ia[arraySize] = {0,3,4,14,1234,1234,1521};

    vector<int> ivect(ia,ia+arraySize);
    list<int> ilist(ia , ia+arraySize);
    deque<int> ideque(ia,ia+arraySize);

    vector<int>::iterator ti1 = find(ivect.begin(),ivect.end(),14);
    if(ti1 != ivect.end())
        cout << " vector has found" << endl;
    else
        cout << " vector has not found" << endl;

    auto ti2 = find(ilist.begin(),ilist.end(),14);
    if(ti2 != ilist.end())
        cout << " list has found" << endl;
    else
        cout << " list has not found" << endl;

    auto ti3 = find(ideque.begin(),ideque.end(),13);
    if(ti3 != ideque.end())
        cout << "ideque has found" << endl;
    else
        cout << " ideque has not found" << endl;
}