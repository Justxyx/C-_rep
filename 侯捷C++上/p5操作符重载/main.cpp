#include <iostream>
using namespace std;

class complex{
private:
    double re,im;
public:
    complex& operator += (complex& a){
        complex c;
        c.re = this->re + a.re;
        c.im = this->im + a.im;
        return c;
    }
    complex(double re = 0 , double im = 0 ) : re(re), im(im) {}
};


int main() {
    complex c1();
    complex c2(12,14);

    return 0;
}


