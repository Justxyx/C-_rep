//
// Created by 肖应雄 on 2021/12/3.
//
#include <iostream>
using namespace std;
#include "list.h"

class Fu{
private:
    int Fu_i;
    int Fu_j;
public:
    Fu() {}

    Fu(int fuI, int fuJ) : Fu_i(fuI), Fu_j(fuJ) {
        cout << " 父类构造函数 " << endl;
    }
    virtual void method(){
        cout << " demo " << endl;
    }
};
class Zi : public Fu{
private:
    int Zi_i;
    int Zi_j;
public:
    Zi(int fuI, int fuJ, int ziI, int ziJ) : Fu(fuI, fuJ), Zi_i(ziI), Zi_j(ziJ) {
        cout << "子类构造函数" << endl;
    }

    void method() override {
        cout << "子类虚函数 " << endl;
    }
};
void test01(){
    Zi z(1,2,3,4);
//    z.method();
//    // 1. 父类指针
//    Fu *f = new Zi(1,2,3,4);
//    f->method();
    // 2. 父类引用
    Fu &fu = z;
    fu.method();
}

class Fu_1{
public:
    virtual void method(){
        cout << " Fu method" << endl;
    }
};

class Zi_1 : public Fu_1{
public:
//    void method(){
//        cout << " Zi method" << endl;
//    }
};

void test02(){
    Zi_1 z;
    Fu_1 &f = z;
    z.method();  //  Zi method
    f.method();  //  Fu method
}

// 纯虚函数
class Fu_2{
public:
    virtual void method() = 0;
    int i,j;

    Fu_2(int i, int j) : i(i), j(j) {}

};

class Zi_2 : public Fu_2{
public:
    int j,k;

    Zi_2(int i, int j, int j1, int k) : Fu_2(i, j), j(j1), k(k) {}

    void method() override {
        cout << " not a virtual method" << endl;
    }
};

class Zi_3 : public Zi_2{
public:
    Zi_3(int i, int j, int j1, int k) : Zi_2(i, j, j1, k) {}
};

void test03(){
}

class Fu_4{
private:
    int i;
public:
    Fu_4(int i) : i(i) {}

protected:
    int x;
};

class Zi_4 : Fu_4{
private:
    int j;
public:
    Zi_4(int i, int j) : Fu_4(i), j(j) {

    }
};

class Fu_5{
public:
    int i;

    Fu_5(int i) : i(i) {}
};

class Zi_5:public Fu_5{
public:
    int i ;

    Zi_5(int i, int i1) : Fu_5(i), i(i1) {

    }

    int getI() const {
        return Fu_5::i;
    }
};

void test05(){
    Fu_5 f(5);
    Zi_5 z(1,2);
    cout << z.getI() << endl;
}

class Fu_6{
public:
    int i;
    Fu_6& operator=(const Fu_6 &f){
        cout << "fu" << "--- " << f.i << endl;
        i = f.i;
        cout << "1" << endl;
        return *this;
    }

    Fu_6(int i) : i(i) {}
};
class Zi_6:public Fu_6{
public:
    int j;
    Zi_6& operator=(const Zi_6 &f){
        Fu_6::operator=(f);
        j = f.j;
        return *this;
    }

    Zi_6(int i, int j) : Fu_6(i), j(j) {}
};
void test06(){
    Zi_6 z(1,2);
    Zi_6 z2(11,21);
    z = z2;
    cout << z.j ;
}

void main1(){
    test06();
//    test05();
//    test02();
//    test01();
}