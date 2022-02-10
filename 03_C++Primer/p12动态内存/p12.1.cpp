//
// Created by 肖应雄 on 2021/11/29.
//
#include <iostream>
using namespace std;
#include "list.h"

void test01(){
//    const StrBlob csb{ "hello", "world", "pezy" };
//    StrBlob sb{ "hello", "world", "Mooophy" };
//
//    std::cout << csb.front() << " " << csb.back() << std::endl;
//    sb.back() = "pezy";
//    std::cout << sb.front() << " " << sb.back() << std::endl;
}

void method(initializer_list<string> li){
    vector<string> vec(li.begin(),li.end());
    for (const auto &item : vec)
        cout << item << endl;
}
void test03(){
    method({"hello","jay","mimi"});
}

class Str{
public:
    using size_type = vector<string>::size_type;
    Str() ;
    Str(initializer_list<string> li);
public:
    shared_ptr<vector<string>> data;
    void check(size_type i,const string &msg) const;
};
Str::Str(initializer_list<string> li) :data(make_shared<vector<string>>(li)){};
Str::Str() :data(make_shared<vector<string>>()){};     // 初始化一个空的 shared_ptr<> 指针

void test04(){
    Str str1{"hello","jay"};
    cout << str1.data << endl;    // 0x600002cd8228
    Str str2 = str1;
    shared_ptr<vector<string>> str3;
//    str3 = str2.data;
    cout << str2.data << endl;    // 0x600003850228
    cout << str1.data.unique() << endl;    // 0
    cout << str1.data.use_count() << endl;   //2
}

class User{
public:
    int age;

    User(int age) : age(age) {}
};

void test05(){
    shared_ptr<int> p1(new int(1024));
    int *p2 = new int(10);
    shared_ptr<int> p3(p2);
    cout << *p3 << endl;

    // 管理指针
    User *u = new User(29);
    shared_ptr<User> user(u);
    cout << user->age << endl;
}

void test06(){
    shared_ptr<string> p1(new string("hello jay"));
    shared_ptr<string> p2;
//    1.p1没有指向任何对象 为空
    if (!p1){
        cout << "is null" << endl;
    }
//    2. p = q;
    p2 = p1;
    cout << *p2 << endl;
//    3.
    cout << p1.unique() << endl;
    cout << p1.use_count() << endl;
}

void method1(shared_ptr<string> ptr){
    cout << *ptr << endl;
    cout << ptr.use_count() << endl;   // 2
    return;
}
void test07(){
    shared_ptr<string> p(new string("hello jay"));
    cout << p.use_count() << endl;  // 1
    method1(p);
    cout << p.use_count() << endl;    // 1


//    错误示范
    string *str = new string("hello");
//    method1(str);  // 错误
    method1(shared_ptr<string>(str));   // 正确的 但是内存会被释放掉
    cout << *str << endl;   // 乱码 内存被释放
}


void test10(){
    shared_ptr<string> p = make_shared<string>("string");
    cout << p << endl;
    cout << *p << endl;
}

void test11(){
    string *str = new string("hello jay");
    shared_ptr<string> p(str);
    cout << str << endl;
    cout << p << endl;
}

void test12(){
    unique_ptr<string> p(new string("hello jay"));
    cout << *p << endl;
    unique_ptr<string> p2 ;
//    p2 = p;  // 错误 unique 为唯一指针
    p2.reset(p.release());
    cout << *p2 << endl;
}

// 删除问题
void test13(){
    unique_ptr<string> p(new string("hello jay"));
    p.release();   // 错误  p不会被释放内存
    auto p2 = p.release();  // p的内存被释放  转为p2
    delete(p2);   // 释放p2
}


// 拷贝问题  原则上unique_ptr 是不允许拷贝赋值的
//1.
unique_ptr<string> method3(string str){
    return unique_ptr<string> (new string(str));
}
//2. 还可以返回一个局部对象的拷贝
unique_ptr<string> method4(string str){
    unique_ptr<string> p(new string(str));
    return p;
}
void test14(){
    auto p = method3("hello");
    auto p2 = method4("hello");
    cout << *p << endl;
    cout << *p2 << endl;
}

void test15(){
    shared_ptr<string> p(new string("hello jay"));
    weak_ptr<string> p1(p);
//    cout << *p1 << endl;   // 因为p1 可能不存在 所以不可以直接访问p1
    if(auto p2 = p1.lock()){     // 如果p1不存在，直接返回false 不会执行下列语句
        cout << *p2 << endl;
        cout << p2.use_count() << endl;
    }
}

void main1(){
    test15();
//    test14();
//    test12();
//    test11();
//    test10();
//    test07();
//    test06();
//    test05();
//    test04();
//    test03();
//    test02();
//    test01();
}
