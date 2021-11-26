//
// Created by 肖应雄 on 2021/11/25.
//
#include <iostream>
#include <tclTomMathDecls.h>
#include <vector>

using namespace std;


//指针形参问题
void test42(int *p){
    cout << p << endl;
    *p = 5;
}
void test41(){
    int i = 12;
    int *p = &i;
    cout << p << endl;
    test42(p);
    cout << *p << endl;
}

//一个统计函数，返回第一次出现的位置以及次数
int test42(const string &str ,char c, string::size_type &sz){
    int count = 0;
    sz = 0;

    for (auto i = 0; i < str.size(); ++i) {
        if (str[i] == c) {
            ++count;
            if (sz == 0){
                sz = i;
            }
        }
    }
    return count;
}

void test43(){
    string str = "jhello jay  jjjj";
    string::size_type sz;
    auto i =  test42(str,'j',sz);
    cout << i << endl;
    cout << sz << endl;
}


//void func1(int i){
//    cout << i << endl;
//}
//void func1(const int i){
//    cout << i << endl;
//}


void test44(){
    int arr[10] = {1,2,4};
}

//string  遍历问题
void test45(){
    string str = "hey xx";
//    1. 普通for循环
    for (const auto &item : str){
        cout << item << endl;
    }
//    2.迭代器
    auto b = str.begin();
    auto e = str.end();
    while (b != e){
        cout << *b << endl;
        ++ b;
    }
}

// 数组问题
void test46(){
    int arr[] = {1,2,3};
//    1. 传统for循环
    for (const auto &item : arr){
        cout << item << endl;
    }
//    2. 迭代器版本
    auto b = begin(arr);
    auto e = end(arr);
    while (b != e){
        cout << *b << endl;
        b ++;
    }
}

//迭代器问题
void test47(){
    vector<int> vec(10,1);
//    1.普通for循环
    for (const auto &item : vec){
        cout << item << endl;
    }
//    2. 迭代器
    auto b = vec.begin();
    auto e = vec.end();
    while (b != e){
        cout << *b << endl;
        ++ b;
    }
}




//1. 没有值传递，本质上是引用传递  不太好判断数组大小
void method11(int arr[]){
    cout << arr << endl;   // 0x16b09b590  传递arr[0]
}

//2. 传递数组收尾指针
void method22(int * p1,int * p2){
    while (p1 != p2){
        cout << *p1 << endl;
        ++ p1;
    }
}

// 3. 传递数组指针与数组大小 显式传递
//略

//4. 直接传递一个数组指针
void method44(int (*p)[10]){
    cout << *(*p) << endl;
}

//5. 引用传递的问题
void method55(int (&arr)[10]){
    for (const auto &item : arr){
        cout << item << endl;
    }
}

void test48(){
    int arr[10] = {1,2,3,4};
    int (*p)[10] ;
    p = &arr;
//    method11(arr);
//    method22(begin(arr), end(arr));
//    method44(p);
    method55(arr);
}


void main4(){
    test48();
//    test47();
//    test46();
//    test45();
//    test43();
//    test41();
}