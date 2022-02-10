#include <iostream>
using namespace std;

/**
 * 转换函数operator double()的意思就是我创建的Fraction对象要可以被转为double。
 * 编译器你在任何需要将Fraction转为doubel的时候，你就来调用我这个函数。
 */

// demo类可以当作一个double类型
class demo{
private:
    int a,b;
public:
    demo(int a, int b) : a(a), b(b) {}
    operator double () const{
        return (double ) (a/b);
    }
};

int main() {

    demo d(12,5);   // int int 会丢失精度
    double b = 3 + d;
    cout << b << endl;
    return 0;
}
