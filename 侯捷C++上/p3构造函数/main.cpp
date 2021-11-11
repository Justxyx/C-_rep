#include <iostream>
using namespace std;

/**
 * 不带指针的类 不用写析构函数
 */
class complex{
public:
    // 函数名冒号后直接初始化，效率会更高一点
    complex(double re, double im) : re(re), im(im) {}

    complex() :re(0),im(0){}

private:
    double re,im;
};

void test01(){
    complex c();
    complex c2(19,12);
}

int main() {


    return 0;
}
