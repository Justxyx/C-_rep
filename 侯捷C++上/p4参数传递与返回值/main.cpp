#include <iostream>
using namespace std;


class complex{
private:
    double re,im;
public:
    complex(double re, double im) : re(re), im(im) {}

    complex& operator +(const complex &a){
        complex c(0,0);
        c.im = this->im + a.getIm();
        c.re = this->re + a.getRe();
        return  c;
    }

    // 加const表示，该函数不可修改private变量 不可修改成员变量
    double getRe() const {

        return re ;
    }
    double getIm() const {
        return im;
    }
};




//演示不加const类的问题
class com{
private:
    int a;
    int b;
public:
    com(int a, int b) : a(a), b(b) {}


    int getA() const  {

        return a;
    }

    int getB()  const {
        return b;
    }
};


int main() {
    complex c1(12,13);
    complex c2(10,10);
    complex c(0,0);
    c = c1 + c2;
    cout << c.getRe() << ":" << c.getIm() << endl;


    return 0;
}
