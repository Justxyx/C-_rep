#include <iostream>
using namespace std;

namespace p1{
    class User{
    public:
        int age;
        void test(){
            cout << "just a test" << endl;
        }
    };

//    1. 成员运算符的访问
        /**
         * 指针访问成员与对象访问成员本质上是没有差别的
         */
    void test01(){
        User u;
        u.test();

        User* u1 = new User;
        u1->test();
        delete u1;
    }

    void main(){
        test01();
    }

}

namespace p2{
//    1.强制类型转换
    void test01(){
        int i = 12;
        double j = static_cast<double>(i);
        cout << j << endl;
    }
    void ma(){
        test01();
    }
}

int main() {
//    p1::test01();
    p2::ma();
    return 0;
}
