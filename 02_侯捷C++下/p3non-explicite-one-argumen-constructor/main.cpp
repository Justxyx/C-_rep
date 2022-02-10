#include <iostream>
using namespace std;

class Fraction{
private:
    double number;
    double den;
public:
    /**
     * explicit 明显告诉编译器 该构造函数只能构造调用 不要把4直接转换为fraction
     * @param number
     * @param den
     */
    explicit Fraction(double number, double den = 1) : number(number), den(den) {}

    operator double() const{
        return (number/den);
    }

    Fraction operator +(const Fraction& f){
        return Fraction((this->number+f.number)/(this->den+f.den));
    }
    double getValue(){
        return number/den;
    }
};

int main() {
    Fraction f(3,5);
    Fraction f2 = f + 4;  // 调用单实参默认函数   4 被直接转换为fraction类   f 也可以转为double 类 出现歧义 编译器报错
    cout << f2.getValue() << endl;
    return 0;
}
