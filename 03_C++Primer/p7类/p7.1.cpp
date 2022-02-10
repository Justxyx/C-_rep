//
// Created by 肖应雄 on 2021/11/23.
//
#include<iostream>
using namespace std;

#include "list.h"

//7.2
class Sale_data{
public:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
void test72(){
    Sale_data total;
    if (cin >> total.bookNo >> total.units_sold >> total.revenue){
       Sale_data trans;
        while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue){
            if (total.bookNo == trans.bookNo){
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            } else{
                cout << total.revenue << "" << total.units_sold << " " << total.bookNo << endl;
                total = trans;
            }
        }
        cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
    } else{
        cerr << " no data ? " << endl;
        return;
    }
    return;
}

//7.3
class Person {
public:
    string name;
    string adderss;
public:
    string get_name() const{
        return name;
    }
    string get_adderss () const{
        return adderss;
    }
};

//7.6
class Sales_data{
public:
    unsigned units_sold = 0;  //销售数量
    double revenue = 0.0;       // 销售收入
    string bookeNo ;            // 数目编号
public:
    string const& isbn() const{  // 返回一个常量的引用
        return bookeNo;
    }
    Sales_data& combin(const Sales_data&);

};
//成员函数一
Sales_data& Sales_data::combin(const Sales_data& rhs){
    units_sold += rhs.units_sold;
    return *this;
}
//非成员函数
istream& read(istream& is,Sales_data salesData){
    double price = 0;
    is >> salesData.bookeNo >> salesData.units_sold >> price;
    salesData.revenue = price*salesData.units_sold;
    return is;
}
std::ostream &print(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue;
    return os;
}
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combin(rhs);
    return sum;
}

//7.9
struct Persons
{
    std::string const& getName()    const { return name; }
    std::string const& getAddress() const { return address; }

    std::string name;
    std::string address;
};
std::istream &read(std::istream &is, Persons &person)
{
    return is >> person.name >> person.address;
}
std::ostream &print(std::ostream &os, const Persons &person)
{
    return os << person.name << " " << person.address;
}

//7.11
class Sales {
public:
    Sales() = default;
    Sales(const std::string &s):bookNo(s) { }
    Sales(const std::string &s, unsigned n, double p):bookNo(s), units_sold(n), revenue(n*p){ }
    Sales(std::istream &is);

    string isbn() const { return bookNo; };
    Sales& combine(const Sales&);

    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;  // 总收入
};

// nonmember functions
istream &read(istream &is, Sales &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &prints(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue;
    return os;
}

Sales adds(const Sales &lhs, const Sales &rhs)
{
    Sales sum = lhs;
    sum.combine(rhs);
    return sum;
}

// member functions.
Sales::Sales(istream &is)
{
    read(is, *this);
}

Sales& Sales::combine(const Sales& rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

//7.16 友元问题
class User{
    friend void test716(int);
    friend class User1;
private:
    int age = 12;
    string name = "xxx";

};
// 友元函数
void test716(int i){
    User user;
    cout <<  user.age << endl;
}
// 友元类
class User1{
public:
    User user;
    void test(){
        cout << user.age << endl;
    }
};
void test7166(){
    User1 user1;
    user1.test();
}


//7.23
class Screen {
public:
    using pos = string::size_type;

    Screen() = default; // 1
    Screen(pos ht, pos wd):height(ht), width(wd), contents(ht*wd, ' '){ } // 2
    Screen(pos ht, pos wd, char c):height(ht), width(wd), contents(ht*wd, c){ } // 3

    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r*width+c]; }

private:
    pos cursor = 0;    // 位置
    pos height = 0, width = 0;
    std::string contents;
};

//7.24 const返回值重载
class Demo724{
private:
    int i = 12;
public:
    friend char Screen::get(pos r, pos c) const ;
    Demo724 &method1(){
        cout << " no const" << endl;
        return *this;
    }
    const Demo724 &method1() const{
        cout << " const " << endl;
        return *this;
    }
};

//7.41 委托构造函数
class Uer41{
private:
    string name;
    string add;
    int age;
public:
    Uer41(const string &name, const string &add, int age) : name(name), add(add), age(age) {}
    Uer41(): Uer41("xx","xxxx",12){};
    Uer41(string str): Uer41(str,"xxxx",12){};
};

//7.47 隐式转换
class User47{
private:
    int age;
public:
    explicit User47(int age) : age(age) {}
};
void test747(){
//    User47 u = 32;
}


//7.56
class User56{
public:
    static  int i  ;
    static void method(){
        cout << "static method" << endl;
    }
};
void test756(){

    User56::method();
}


void main1(){
    test756();
//    test7166();
//    test716(11);
//    test72();

}