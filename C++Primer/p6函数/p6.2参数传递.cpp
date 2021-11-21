//
// Created by 肖应雄 on 2021/11/19.
//

#include <iostream>
using namespace std;
#include "list.h"


//6.10
void swap_main2(int *a,int *b) {
    int *temp = a;
    *a = *b;
    *b = *temp;
}
void test610(){
    int a = 12;
    int b = 13;
    swap_main2(&a, &b);
    cout << a << endl;
}

//6.11
void swap_test611(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}
void test611(){
    int a = 1,b = 12;
    swap_test611(a,b);
    cout << a << endl;
    cout << b << endl;
}

//6.15
void find_char(const string &str,char c,string::size_type &count){
    auto size = str.size();
    count = 0;
    for (auto i = 0;  i != size ; i++) {
        if(str[i] == c){
            ++ count;
        }
    }
}
void test615(){
    string s = "hello word";
    string::size_type count_i ;
    char c = 'o';
    find_char(s, c, count_i);
    cout << count_i << endl;
}

//6.151 // const 指针问题
void test6151(){
//    const int i = 12;
//    const int &j = i;  // 引用必须初始化
//    j = 43;  错误 对常量的引用不可更改
//    int &j2 = i;   错误 非常量引用指向常量对象

//    int errNum = 0;
//    int * const p = &errNum;  // p指针不再改变
//    int errBug = 1;
//    const int *p1 = &errBug;   // p1 指针内容不再改变

//    const int i = 5;
//    constexpr int j = i;

    class User{
    public:
        int age;
    };


}

//6.16
bool isEmpty(const string& str){
    return str.empty();
}
void test616(){
    const string s1 = "hello word";
    bool  b =  isEmpty(s1);
    cout << b << endl;
}

//6.17



void main2(){
//    test610();
//    test611();
//    test615();
    test616();
}