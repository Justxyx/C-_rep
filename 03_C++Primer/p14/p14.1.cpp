//
// Created by 肖应雄 on 2021/12/3.
//
#include <iostream>
#include <vector>

using namespace std;

class User{
public:
    string name;
    int age;
public:
    User(const string &name, int age) : name(name), age(age) {}
    User &operator++(int){
        ++age;
        cout << "  ++  " << endl;
    }
    User() {}
};
void test07(){
    User u("xx",12);
    u ++;
}


ostream &operator<<(ostream &os,const User &user){
    os << user.name << " -- " << user.age ;
    return os;
}
void test01(){
    User u1("xx",12);
    cout << u1 << endl;
}

void test02(){
    int i ,j ;
    cin >> i >> j ;
    cout << i << j << endl;
}

istream &operator>>(istream &is,User &user){
    is >> user.name >> user.age ;
    if (!is)
        user = User();
}
void test03(){
    User user;
    cin >> user ;
}


bool operator==(const User &u1,const User &u2){
    return (u1.age == u2.age) && (u1.name == u2.name);
}

void test04(){
    User u1("xx",12);
    User u2("xx",12);
    cout << &u1 << endl;
    cout << &u2 << endl;
    if (u1 == u2){
        cout << "yes";
    }
}

void method2(initializer_list<string> li){
    auto e = li.end();
    auto b = li.begin();
    vector<string> c(b,e);
}


void test05(){
    int a[5] = {1,2,3,4,5};
    cout << a[1] << endl;
}

class User2{
public:
    int age;
    User2() {}
    User2(int age) : age(age) {}
    void operator()(int i){
        cout << i << endl;
    }
};

void test08(){
    User2 u;
    u(2);
}

class PrintString{
public:
    PrintString(ostream &os = cout, char sep = ' ') : os(os), sep(sep) {}
    void operator()(const string& s) const{
        os << s << sep;
    }
private:
    ostream &os;
    char sep;
};
void test09(){
    PrintString p;
    p("hello jay");
    PrintString p2(cerr,'\n');
    p2("hey");
    p2("hey");
}

void main1(){
//    test09();
//    test08();
//    test07();
//    test05();
//    test04();
//    test03();
//    test02();
//    test01();

}
