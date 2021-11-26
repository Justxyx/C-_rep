//
// Created by 肖应雄 on 2021/11/24.
//

#include <iostream>
#include <vector>

using namespace std;

void test11(){
    string str = "hey";
    string::size_type i = str.size();   // size_type为无符号数  不要与int比较
    cout << i << endl;
}

void test12(const string& str1,const string& str2){
    str1.size() > str2.size() ? cout << str1 : cout << str2;
    return;
}
void test13(){
    test12("hello","hey");
}

void test14(){
    string str;
    string st = "";
    while (true){
        cin >> str ;
        if (str == "-1") break;

        st += str;
    }
    cout << st << endl;
}
void test15(){
    test14();
}


void test16(){
    string str = " hello jay";
    for ( auto &item : str){
        item = 'X';
    }
    cout << str << endl;
}

void test17(){
    string str = "hello jay";
    string::size_type i = 0;
    while (i < str.size()){
        str[i] = 'x';
        i++;
    }
    cout << str << endl;
}

//vector<> 初始值问题
void test18(){
    vector<int> v(10);   // int 类型 默认为0
    for (const auto &item : v){
        cout << item << endl;
    }
}

class User{
public:
    int age;
    string name;
};
void test19(){
    vector<User> v(10);
    for (const User &item : v){
        cout << item.age << endl;
    }
}

void test20(){
    vector<int> v(10,0);
    vector<int>::size_type i = v.size();
    cout << i << endl;
    for (const auto &item : v) cout << item << endl;
}

void test21(){
    // 迭代器问题
    vector<int> v (10,0);
//    for (const auto &item : v) {
//        cout << item << endl;
//    }
    auto b = v.begin();
    auto e = v.end();

    while(b != e){
            cout << *b << endl;
            ++ b;
    }
}

//const 问题
void test22(){
    vector<int> c  (10,1);
    auto b = c.cbegin();
    auto e = c.cend();
}

//数组引用问题
void test23(){
    int arr[10] = {1,2};
    int (&arr2)[10]  = arr;
    arr2[1] = 333;
    for (const auto &item : arr2)
        cout << item << endl;
}

//数组指针问题
void test24(){
    int arr[10];
    for ( auto &item : arr)
        item = 1;
    int *p1 = begin(arr);
    int *p2 = end(arr);
    while ( p1 != p2){
        cout << *p1 << endl;
        ++ p1;
    }
}

int test25(){
    static int i = 25;
   return i ++;
}

void test26(){
    int i = test25() + test25();
    cout << i << endl;
}

void test27(){
    int i = 12;
    void *p = &i;
    int *p2 = static_cast<int*>(p);
    cout << *p2 << endl;
}


//
void test28(){
   const int *p ;
   int i = 12;
   p = &i;
   int *p2 = const_cast<int*>(p);
   cout << *p << endl;
   cout << "--------" << endl;
   cout << *p2 << endl;
   *p2 = 11;
    cout << *p2 << endl;
}

void main1(){
    test28();
//    test27();
//    test26();
//    test24();
//    test23();
//    test21();
//    test20();
//    test19();
//    test18();
//    test17();
//    test16();
//    test15();
//    test13();
//    test12();
//    test11();
}