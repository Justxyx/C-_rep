//
// Created by 肖应雄 on 2021/11/10.
//

#ifndef P2_COMPLEX_H
#define P2_COMPLEX_H




class Complex {
private:
    double re,im;
public:

    Complex(double re, double im) : re(re), im(im) {}

    // const函数
    double getRe() const {
        return re;
    }
    double getIm() const {
        return im;
    }

    void setRe(double re) {
        Complex::re = re;
    }

    void setIm(double im) {
        Complex::im = im;
    }

};


#endif //P2_COMPLEX_H
