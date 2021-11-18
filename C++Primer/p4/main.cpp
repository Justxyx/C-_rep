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

int main() {
    p1::test01();
    return 0;
}
