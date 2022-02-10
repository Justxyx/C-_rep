#include <iostream>
#include "string.h"
using namespace std;


// 模板全特化
/**
 * 模板泛化其实是一个很简单的概念
 *      简单来说就是 能找到对应的模板 我就调用对应的模板
 *      如果找不到对应的模板 我就调用公共的模板
 */
namespace p10{

    template <class T>
    class test{
    public:
        void method(){
            cout << "模板泛化" << endl;
        }
    };

    template<>
    class test<long>{
    public:
        void method(){
            cout << "模板泛化 2 " << endl;
        }
    };

    void demo(){
        test<int> t;
        test<long> t2;
        t.method();
        t2.method();
    }
}


// 模板偏特化
/**
 * 1. 数量上的偏特化
 *         三个模板，可以都不指定，也可以先指定第一个
 * 2. 范围上的偏特化
 *         可以指定所有 也可以指定仅指针可以
 */
namespace p11{

    // 数量上的特化
    template <class T1,class T2,class T3>
    class Test{
    public:
        void method(){
            cout << "简单的模板特化" << endl;
        }
    };
    template <class T2,class T3>
    class Test<int,T2,T3>{
    public:
        void method(){
            cout << "特化1" << endl;
        }
    };

    // 范围上的特化
    template<class T>
    class Test01{
    public:
        void method(){
            cout << "范围上的特化 11" << endl;
        }
    };

    template<class T>
    class Test01<T*>{
    public:
        void method(){
            cout << "指针特化" << endl;
        }
    };


    void demo(){
        Test<long,long,long> t;
        Test<int,long,long> t1;

        Test01<int*> t3;
        t3.method();
        t1.method();
    }
}

/**
 * C++ 11
 * 201103
 */
namespace p12{
    void demo(){
        cout << __cplusplus << endl;
    }
}

/**
 * 2.0新特性
 * 1. 数量不定的模板参数
 * 2. auto   自动赋值 不用指定变量类型
 *

 */
namespace p13{

    template<typename T,typename... Types>
    void print(const T& firstArg,const Types&... args){
        cout << firstArg << endl;
        print(args...);
    }

    void test02(){
//        print(1,333,3333,12);
        auto i = 2;
        cout << i << endl;
    }
}

/**
 * 引用问题
 *      ** 别名只能起一次 **
 *      int a  = 5;
 *      int& r = a;
 *      int b = 12;
 *      r = b;
 *      引用本质上还是指针
 *
 *      reference 的三种用途：
 *      1. void method(Cls* p)  指针传递
 *      2. void method(Cls p)   按值传递
 *      3. void method(Cls& p)  引用传递 比较快
 */
namespace p14{
    void test01(){
        double x = 10;
        double* p = &x;
        double& r = x;

        cout << sizeof (x) << endl;
        cout << sizeof (p) << endl;
        cout << sizeof (r) << endl;

        cout << "-----------" << endl;
        cout << p << endl;
        cout << *p << endl;
        cout << x << endl;
        cout << r << endl;
        cout << &x << endl;
        cout << &r << endl;


    }
}


/**
 * const 的一些用法
 */
namespace p20{
    class User{
    private:
        int age;
        string name;

    public:
        User(int age, const string &name) : age(age), name(name) {}

        // 1. 用法1， 放在成员函数的后面，全局函数不可放 成员函数不改变成员变量
        int getAge() const{
            return age;
        }

//        2. const是属于签名的, 可以发生重载
        /**
         * 当 const 与 non-const 版本同时存在的时候
         * 常量对象只会调用 const 版本 非常量对象调用no-const版本
         * @return
         */
        int getAge(){
            cout << "no-const调用" << endl;
            return age;
        }

    };

    void test(){
        // const 变量只能调用const成员函数
        const User user(123,"xx");   // 常量对象
        int age =  user.getAge();

        User user2(1,"zz");

        cout << age << endl;
        cout << user2.getAge() << endl;
    }
}




int main() {
//    p10::demo();
//      p11::demo();
//    p12::demo();
//    p13::test01("hello",1,3,4444,41342);
//    p13::test02();
//        p14::test01();
        p20::test();
    return 0;
}


