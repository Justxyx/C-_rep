//
// Created by 肖应雄 on 2021/11/26.
//

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <array>
#include "string"


using namespace std;
void test01(){
    vector<int> v; // 1. 可变数组
    deque<int> d;  // 2. 双端队列
    list<int> li;  //3. 双向链表
    forward_list<int> fli;  //4. 单向链表
    array<int,10> arr;    //5.固定数组
    string s;           //7.字符串
}

void test02(){
    vector<int> vec = {1,2,2,3};

    vector<int>::iterator;  //1.迭代器类型
    vector<int>::const_iterator ; // 2. const 迭代器
    vector<int>::size_type ;   //3. 无符号整数  保存容量大小
    vector<int>::difference_type ;  // 4. 有符号整数， 足够保存两个迭代器之间的距离
}

void test03(){
    vector<int> vec = {1,2,2,3};
    auto b = vec.begin();
    auto e = vec.end();
    while (b != e){
        cout << *b ++ << endl;
    }
    *b = 12;

    auto cb = vec.cbegin();
    auto ce = vec.cend();
}

void test04(){
    list<string> li = {"hello","jay","just"};
    for (const auto &item : li)
        cout << item << endl;
    list<string> li2(li);   // 正确
//    vector<string> vec(list);  // 错误
    vector<string> vec(li.begin(),li.end());   // 可用首尾指针构造 不同类型的构造器
    for (const auto &item : vec)
        cout << item << endl;
}

void test05(){
//    1. array 使用时必须指定大小
    array<int,10> a1 = {1,2,3,4};
//    2. 内置数组没有拷贝赋值，array可以
    array<int,10> copy = a1;
    cout << &a1 << endl;
    cout << &copy << endl;
}

void test06(){
    vector<int> vec1 = {1,2,2,3,4,5};
    vector<int> vec2 = {1,2,2,3,4,5};
//    1.
//    vec2.assign(vec1.begin(), -- vec1.end() );
//    2.
    vec2.assign(10,1);
    for (const auto &item : vec2)
        cout << item << endl;
}

void test07(){
    vector<int> vec1 = {1,2,2,3,4,5};
    cout <<  vec1.size() << endl;
    cout << vec1.empty() << endl;
    cout << vec1.max_size() << endl;
}

void test08(){
    vector<int> vec1 = {1,2,2,3,4,5};
    vec1.push_back(12);  // 尾插
    vec1.insert(vec1.begin(),12);  // 头插
    for (const auto &item : vec1)
        cout << item << endl;
}

void test09(){
    vector<int> vec1 = {1,2,2,3,4,5};
    cout << vec1.front() << " --- " << vec1.back() << endl;  // 头尾元素
    auto v1 = vec1[1];
}

void test10(){
    vector<int> vec1 = {1,2,2,3,4,5};
    vec1.pop_back();   // 删除尾元素
    auto p = vec1.begin();
    vec1.erase(p);  // 删除指定迭代器元素
    vec1.erase(vec1.begin(),++vec1.begin());
    vec1.clear();
}

void test11(){
    vector<int> v(5,1);
    v.resize(10);
    for (const auto &item : v)
        cout << item << endl;
    v.resize(2);
    for (const auto &item : v)
        cout << item << endl;
}

void test12(){
    vector<int> c(10,1);
    cout << c.capacity() << endl;
}

void test13(){
    string str = "hello jay";
    string s(str,1,2);
    cout << s << endl;
}

void test14(){
    string str = "hello jay";
    auto s = str.substr(3,3);
    cout << s << endl;
}

void test15(){
    string s1 = "hello jay",s2 = "jay";
    cout <<  s1.compare(s2);
}

void test16(){
    int val = 12;
    cout << to_string(val) << endl;
}

void main1(){
    test16();
//    test15();
//    test13();
//    test12();
//    test11();
//    test10();
//    test09();
//    test08();
//    test07();
//    test06();
//    test05();
//    test04();
//    test03();
//    test02();
}