//
// Created by 肖应雄 on 2021/11/19.
//

#include <iostream>
using namespace std;
#include "list.h"


//    6.1练习
int face(int i){
    int res = 1;
    while (i){
        res *= i --;
    }
    return res;
}
void test01(){
    //        int j = face(5);
//        cout << j << endl;
    cout << "请输入一个数字：" << endl;
    int j;
    cin >> j;
    cout << "阶乘为：" << face(j)<< endl;
}

//    .练习6.6
void test02(int i){
    static int count ; // 初始值为0；
    int j = 12;
}

//    练习6.7
int method1(){
    static int count ;
    return count++;
}
void test03(){
    for (int i = 0; i < 100; ++i) {
        cout << method1() << endl;
    }
}

void main1(){
    test01();
    test02(5);
    test03();
}