//
// Created by 肖应雄 on 2021/11/26.
//
#include <iostream>
#include <vector>
#include "algorithm"
#include <numeric>
#include <list>

using namespace std;

//1.find 算法
void test01(){
    vector<int> v = {1,323,141,513,1351,531,13};
    auto result = find(v.cbegin(),v.cend(),323);
    if (result == v.cend()){
        cout << " not find " << endl;
    } else{
        cout << *result << endl;
    }
}

//2. 求和算法
void test02(){
    vector<int> v = {1,323,141,513,1351,531,13};
    int sum = accumulate(v.cbegin(),v.cend(),0);
    cout << sum << endl;
}

void test03(){
    string str = "hello jay";
    auto p = str.begin();
    auto p2 = str.end();
//    while (p != p2){
//        cout << *p << endl;
//        p ++;
//    }
    vector<string> v = {"hello","jay","sunnyday"};
//    for (const auto &item : v)
//        cout << item << endl;
    string s1 =  *v.cbegin()  + *v.cend();
    cout << s1 << endl;
    string s2 = "hello ";
    string s3 = "hey ";
    cout << s2 + s3 << endl;
}

void test04(){
    vector<int> v1 = {1,23,4};
    vector<int> v2 = {1,23,4};
    auto b = equal(v1.begin(),v1.end(),v2.begin());
    cout << b << endl;
}

void test05(){
    vector<int> v = {1,3,4,5};
    fill(v.begin(),v.end(),10);
//    for (const auto &item : v)
//        cout << item << endl;
//    fill_n(v,3,1);
//    for (const auto &item : v)
//        cout << item << endl;
//    list<int> li;
//    cout << li.size() << endl;

    vector<int> v2 ;
//    fill_n(v2,10,4);  // 错误 v2为空
    auto it = back_inserter(v2);
    fill_n(it,10,3);
    for (const auto &item : v2)
        cout << item << endl;

}

void test06(){
    int a1[ ] = {1,2,3,4,5,6,7};
    cout << a1 << endl;
    cout << sizeof(a1) << endl;   //28
    cout << sizeof(*a1) << endl;  // 4
//    数组大小
    cout << sizeof(a1) / sizeof (*a1) << endl;
}

void test07(){
    int a1[ ] = {1,2,3,4,5,6,7};
    int a2[10];
    copy(begin(a1), end(a1),a2);
    for (const auto &item : a2)
        cout << item << endl;
    replace(begin(a1), end(a2),1,3);
    for (const auto &item : a1)
        cout << item << endl;

}

void test08(){
    vector<int> v = {1,2,3,4,5,6,7,1,2,4};
    sort(begin(v), end(v));
    auto end_unique = unique(begin(v), end(v));
    v.erase(end_unique,v.cend());
    for (const auto &item : v)
        cout << item << endl;
}

bool isShort(string& str1,string& str2){
    return  str1.size() < str2.size();
}
void test09(){
    vector<string> vec = {"hello","jay","xx"};
    std::sort(vec.begin(), vec.end(), isShort);
    for (const auto &item : vec)
        cout << item ;
}

void test10(){
    list<int> l1 = {1,2,3,4,5};
    list<int> l2,l3;
    copy(l1.begin(),l1.end(), front_inserter(l2));
    for (const auto &item : l2)
        cout << item << endl;
    copy(l1.begin(),l1.end(), back_inserter(l2));
    for (const auto &item : l2)
        cout << item << endl;
}

void test11(){
    // 反向迭代器问题
    list<int> list = {1,2,3,4,5,6,7,8,9,10};
    auto b = list.rbegin();
    auto e = list.rend();
    while ( b != e){
        cout << *b << endl;
        ++ b;
    }
}


void main1(){
    test11();
//    test10();
//    test09();
//    test08();
//    test07();
//    test06();
//    test05();
//    test04();
//    test03();
//    test01();
//    test02();

}