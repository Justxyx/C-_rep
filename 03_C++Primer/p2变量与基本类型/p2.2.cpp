//
// Created by 肖应雄 on 2021/11/24.
//

#include <iostream>
using namespace std;
#include "list.h"

int i = 42;
void test221(){
    cout << i << endl;
    int i = 100;
    cout << i << endl;
}

void test222(){
    int i , &ri = i;
    i = 5;
    ri = 10;
    cout << i << " -- " << ri << endl;
}

// 空指针问题
void test223(){
    int *p = nullptr;
    int *p1 = 0;
    int *p2 = NULL;

    if (p1 == p2){
        cout << "1" << endl;
    }
}

void test2_18(){
    int i = 12,j = 23;
    int *p = &i;
    // 更改指针的值
    *p = 22;
    p = &j;// 更改指针指向的对象
}

void test2_22(){
    int *p = nullptr;
    if (!p){
        cout << "1" << endl;
    }
    int i = 12;
    p = &i;
    cout << *p << endl;
    if (*p){
        cout << "2" << endl;
    }
}

//void test224(){
//    //1. 指向指针的指针
//    int i = 12;
//    int *p = &i;
//    int **r = &p;
//    cout << p << endl;
//    cout << r << endl;
//
//    //2. 指向指针的引用
//    int i = 12;
//    int *p = &i;
//    int *&r = p;
//    *r = 1;
//    cout << i << endl;
//}


//extern const int con = 25;
////const 定义与声明
//void test225(){
//}


void test226(){
    int i = 12;
    const int &r = i;
    i = 18;
    cout << r << endl;
}

 // 指向常量的指针
void test227(){
    int i = 12;
    const int *p  = &i;
    int j  = 11;
//    *p = &j; // 错误
    i = 11;  // 正确
}

void test229(){
    int i=1,j=2;
    const int *p = &i;  // 底层指针，指向常量的指针
//    *p = 2;
    int *const r = &j;  // 顶层指针，常量指针
}


// auto 的顶层指针会被忽略掉
void test230(){
    const int i = 12;
    auto j = i;
    j = 15;
    cout << j << endl;   // auto 自动忽略掉了顶层const j=15
}



void main2(){
    test230();
//    test226();
//    test224();
//    test2_22();
//    test223();
//    test222();
//    test221();
}