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
    z.method();
    // 1. 父类指针
    Fu *f = new Zi(1,2,3,4);
    f->method();
    // 2. 父类引用
    Fu &fu = z;
    fu.method();
}
void main1(){
    test01();
}