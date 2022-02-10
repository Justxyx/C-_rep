//
// Created by 肖应雄 on 2021/11/26.
//

#include<iostream>
#include <vector>

using namespace std;

#include "list.h"
#include "vector"

class Sales_data
{
public:
    string bookNo;  //书号
    unsigned units_sold = 0;  //数目
    double revenue = 0.0;   // 价格
};
int test721()
{
    Sales_data total;
    if (cin >> total.bookNo >> total.units_sold >> total.revenue)
    {
        Sales_data trans;
        while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue)
        {
            if (total.bookNo == trans.bookNo)
            {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            }
            else
            {
                cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
                total = trans;
            }
        }
        cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
    }
    else
    {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}

class demo721{
private:
    int age = 12;
public:
    int getAge() const {
        return age;
    }
};
void test722(){
    demo721 d;
    auto i = d.getAge();
    /**
     * 调用逻辑：
     *      d.getAge()   ->  demo721::getAge(&d);
     *      return this->age;
     */
}

void test723(){
    demo721 d2;   // 类似于     demo721 const *p 顶层指针  。  this 指针的指向不可改变。 this 为常量指针
    /**
     * 形参列表后面 跟 const 改变了this指针的类型   this 指向的当前对象为常量
     */

}

class Demo722{
private:
    int age;
public:
    double average( );
};

// 在类中声明，在类外定义
double Demo722::average() {
}


//类的拷贝问题
class Demo723{
private:
    int age;
    string name;
    vector<int> v;
public:
    Demo723(int age, const string &name, const vector<int> &v) : age(age), name(name), v(v) {}
    Demo723() = default;  // 默认构造函数

    int getAge() const {
        return age;
    }

    const string &getName() const {
        return name;
    }

    const vector<int> &getV() const {
        return v;
    }
};

void test725(){
    vector<int> v(10,1);
    Demo723 d(1,"xx",v);
    Demo723 d2 = d;
    /**
     *     d2.name = d.name;
            d2.age = d.age;
            d2.v = d.v;
     *
     */
    cout << &d2.getV() << endl;   // 0x16d41f518
    cout << &d.getV() << endl;    // 0x16d41f578
}


//可变数据成员
class Demo724{
private:
    mutable int age = 10;
public:
    int getAge() const{
        return  ++ age;
    }
};
void test727(){
    Demo724 d;
    cout << d.getAge() << endl;
}


void main2(){
    test727();
//    test725();
//    test722();

}