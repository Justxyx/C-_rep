//
// Created by 肖应雄 on 2021/11/22.
//

#include <iostream>
#include <array>

using namespace std;
#include "list.h"

//1. 数组别名问题
void test601(){
    typedef int arrT[10];   // 这个语法好奇怪，arrT别名，表示int【10】；
    using arrT = int[10];   // 与上一个等价 别名
}
//2. 数组指针
void test602(){
    int arr[10] = {1,2,4,5};
    int* p[10];    // 含有十个指针的数组   ->  int *p[10]
    int (*p2)[10];    // p2为一个指针，指向含有十个整数的数组  指针的指针 有点绕晕了

    p2 = &arr;      // 存放arr指针的指针
    cout << *(*p2) << endl;    //  第一次解引用得到数组第一位地址 第二次解引用得到arr[0];

    int *p4 = arr;              //  arr 本身就是指针
    cout << *p4 << endl;


}


//3.尾置返回类型 Cpp11
auto test603()->int(*)[10]{   // 返回一 指向数组的一个指针
    int arr[10] = {1,2,4};
    return &arr;
}
void test604(){
    auto p = test603();
    cout << *(*p) <<endl;
}

//4. decltype 返回
int arr[10] = {1,3,4,5};
decltype(arr)* test605(){
    int arr[10] = {1,2,4};
    return &arr;
}
void test606(){
    auto p = test605();
    cout << *(*p) <<endl;
}



// 1.函数指针的定义
bool  test608(int a,int b){
    return a>b? true: false;
}
void test607(){
    bool  (*p)(int a,int b);  // 声明函数指针
    p = test608;        // 指向函数
//    p = &test608;     等价
    cout << p(1,2) << endl;
}

//2.函数指针的重载
//略  与函数重载规则基本类似

//3. 返回指向函数的指针
//1. 别名
using p = bool(*)(int,int); //函数指针
using pf = bool(int,int); // 函数类型 不是指针
p test609(){
    return test608;
}
void test6101(){
    p f;
    f = test609();
    cout << f(1,2) << endl;
}
//2. 尾置返回
//略
//3. 使用decltype简化
decltype(test608) *test6102(){
    return test608;
}
void test6103(){
    p f;
    f = test609();
    cout << f(1,2) << endl;
}


void main3(){
    test6103();
//    test6101();
//    test609();
//    test607();
//    test606();
//    test604();
//    test602();
//    test601();
}