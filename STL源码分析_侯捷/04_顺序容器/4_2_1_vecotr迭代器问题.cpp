//
// Created by 肖应雄 on 2021/12/29.
//
#include <iostream>
using namespace std;
#include <vector>

/**
 * 写点笔记:
 *      vector 动态增加大小，并不是在原有的基础上续接空间的。
 *      一旦空间位置重新分配，原来指向vector的指针迭代器就失效了！！！！！！
 */
int main421(){
    vector<int> v(10,12);
    vector<int>::iterator p = v.begin();
    cout << *p << endl;
    for (int i = 0; i < 1000; ++i) {
        v.push_back(i);
    }
    cout << *p << endl;   //  迭代器已经失效
}