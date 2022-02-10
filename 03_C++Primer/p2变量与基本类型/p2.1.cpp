//
// Created by 肖应雄 on 2021/11/24.
//

#include <iostream>
using namespace std;
#include "list.h"
// 无符号数问题
void test21(){
    // 当明确直到变量不可能为负数时，用unsigned
    unsigned int i = -1;
    cout << i << endl;
}


// 有符号数 超出定义时 结果显示为为定义的
void test22(){
    signed char i = 257;
    cout << i << endl;
}

// 无符号数与有符号数参与运算，有符号数会转换为无符号数
void test23(){
    unsigned i = 12;
    int j = -1;
    cout << i*j <<endl;  // 4294967284
}

void main1(){
    test23();
//    test22();
//    test21();
}