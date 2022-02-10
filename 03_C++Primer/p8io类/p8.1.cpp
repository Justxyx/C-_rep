//
// Created by 肖应雄 on 2021/11/24.
//
#include <iostream>
using namespace std;
#include "list.h"

void test01(){
    int i ;
    cin >> i;
    cout << i;
}

// 错误的输入状态将跳出循环
void test02(){
    int i;
    while(cin >> i){
        cout << i;
    }
    return;
}

istream& method1(istream& i){
    string buf;
    while (i >> buf){
        if (buf == "1") break;
        cout << buf << endl;
    }
    return i;
}
void test03(){
    istream& is = method1(std::cin);
    std::cout << is.rdstate() << std::endl;
    return ;
}

void test05(){
    cout << "hey " << endl;
    cout << "hey " << flush;
    cout << "hey " << ends;
}


void main1(){
//    test05();
//    test03();
//    test02();
//    test01();
}