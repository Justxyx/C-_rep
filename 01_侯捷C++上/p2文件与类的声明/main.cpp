#include <iostream>
#include "Complex.h"
using namespace std;
//#include "Complex.h"


/**
 * 笔记：
 *      关于const对用法：
 *          1. int method const(){
 *               xx
 *              }
 *              const  成员函数， 不可以修改成员变量。
 *
 *           2. 友元函数与友元类
 *              1. 友元函数，可以读取类的private数据。
 *              2. 友元类
 *
 *           3. 模版类
 *
 */


class Point {
private:
    int x;
    int y;
public:
    Point(int x, int y) : x(x), y(y) {}
    friend void dist(Point &A,Point &B);
};

void dist(Point &A,Point &B){
    cout<< "x1 - x2 is: "<< A.x - B.x << endl;
    cout << "y1 - y2 is "<< A.y -B.y << endl;
}

// 友元函数
void test01(){
    Point A(12,15);
    Point B(4,5);
    dist(A,B);
}

// 友元类
class A{
private:
    int a;
public:
    friend class B;
};

class B{
private:
    A a;
public:
    B(const A &a) : a(a) {}

    void setA(int i){
        a.a = i;
    }
};

//模版类

template<class T>
class tem{
private:
    T a;
    T b;
public:
    tem(T a, T b) : a(a), b(b) {}

    void out(){
        cout << "a: " << a << endl;
        cout << "b: " << b << endl;
    }
};


void test03(){
    tem<int> tem(1,2);
    tem.out();
}

int main() {
//    1.友元函数
    test01();
//    2. 友元类问题
//    3. 模版类问题
    test03();
    return 0;
}
