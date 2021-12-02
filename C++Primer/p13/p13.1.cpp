//
// Created by 肖应雄 on 2021/12/1.
//
#include <iostream>
using namespace  std;

//1. 拷贝构造初探究
class User{
private:
    int age;
    string name;
public:
    const string &getName() const {
        return name;
    }
    User& operator=(const User &u){
        age = u.age;
        name = u.name;
        cout << "赋值构造啦" << endl;
        return *this;
    }
    explicit User(int age, const string &name) : age(age), name(name) {}
//    User(const User& user) :age(user.age),name(user.name){}  // 与默认拷贝构造类似 编译器默认拷贝构造
};
void test01(){
    User user(10,"jay");
    User u2 = user;
//    User u3 = {10,"jar"};  // 没加 explicit 是对的  加了就报错  不能走默认构造函数，只能走拷贝
    cout << u2.getName() << endl;
}

void test02(){
    User u(10,"jay");

//    cout << u2.getName() << endl;
}

class Demo{
private:
    int i;
public:
    ~Demo(){
        cout << "析构函数调用";
    }
};
void test03(){
    Demo d;
}


class Number{
public:
    Number() {
        mysn = unique ++;
    }

public:
    int mysn;
    static int unique;
};
int Number::unique = 10;
void f(Number n){
    cout << n.mysn << endl;
}
//13.14
void test04(){
    Number a,b=a,c=b;
    f(a);
    f(b);
    f(c);
}



class numbered {
public:
    numbered() {
        mysn = unique++;
    }
    numbered(const numbered& n)
    {
        cout << "拷贝构造" << endl;
        mysn = unique++;
    }

    int mysn;
    static int unique;
};

int numbered::unique = 10;

void f(numbered& s) {
    std::cout << s.mysn << std::endl;
}

void test05()
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
}


class Demo1{
public:
    int age;
    Demo1& operator=(const Demo1& d){
        age += d.age;
        return *this;
    }
};
void test06(){
    Demo1 d1,d2;
    cout << d1.age << endl;
    d2.age = 10;
    d1 = d2;
    cout << d1.age << endl;
}

class Demo3{
public:
    Demo3(const Demo3&) = delete;  // 禁止构造拷贝
    Demo3& operator =(const Demo3&) = delete;   // 禁止值拷贝
    Demo3() {};
};
void test07(){
    Demo3 d,d1;
//    d(d1);
}


class Emplpyee{
public:
    string name;
    int id;
public:
    static int unique_id;
    Emplpyee(const Emplpyee&) = delete;
    Emplpyee& operator=(const Emplpyee&) = delete;
    Emplpyee(const string &name) : name(name) {
        id = unique_id ++;
    }
};
int  Emplpyee::unique_id = 10;
void test08(){
    Emplpyee e("jay");
    Emplpyee e1("jay1");
    Emplpyee e2("jay2");
//    e1 = e;
//    e2(e);
    cout << e.id << " " << e2.id << " " << e1.id << endl;
    cout << e.name << " " << e2.name << " " << e1.name << endl;

}

// 行为像值的类
//class HasPtr{
//public:
//    HasPtr(const string &str): ps(new string(str)),i(0)
//    {};
//    // 拷贝赋值
//    HasPtr& operator=(const HasPtr &rhs){
//        cout << "拷贝赋值" << endl;
//        auto newp = new string(*rhs.ps);
//        delete ps;
//        ps = newp;
//        i = rhs.i;
//        return *this;
//    }
//    // 拷贝构造
//    HasPtr(const HasPtr &p):ps(new string(*p.ps)),i(p.i){
//        cout << "拷贝构造" << endl;
//    }
//    string *getPs() const {
//        return ps;
//    }
//    // 析构函数
//    ~HasPtr(){
//        delete ps;
//    }
//private:
//    string *ps;
//    int i;
//};

//void test10(){
//    string str = "hello jay";
//    HasPtr p1(str);
//    HasPtr p2("xx");
//    HasPtr p3(p2);
//}


// 行为像指针的类
class HasPtr{
public:
    HasPtr(const string &str): ps(new string(str)),i(0),use(new size_t(1))
    {};
    // 拷贝赋值
    HasPtr& operator=(const HasPtr &rhs){
        cout << "赋值构造" << endl;
        ++ *rhs.use;
        if ( -- *use == 0){
            delete ps;
            delete use;
        }
        ps = rhs.ps;
        i = rhs.i;
        use = rhs.use;
        return *this;
    }
    // 拷贝构造
    HasPtr(const HasPtr &p):ps(new string(*p.ps)),i(p.i),use(p.use){
        ++ *use;
        cout << "拷贝构造" << endl;
    }
    string *getPs() const {
        return ps;
    }
    // 析构函数
    ~HasPtr(){
        if ( --*use == 0){
            cout << "调用析构函数" << endl;
            delete ps;
            delete use;
        }
    }
private:
    string *ps;
    int i;
    size_t *use;
};

void test11(){
    HasPtr h1("xx");
    HasPtr h2 = h1;
//    h2  =  h1;
}


class Demo33{
private:
    int age;
    string name;
public:
    Demo33(int age, const string &name) : age(age), name(name) {}
    Demo33(Demo33 &d):age(d.age),name(d.name){
        cout << "调用拷贝构造" << endl;
    }
    Demo33& operator=(const Demo33& d){
        cout << "调用拷贝赋值" << endl;
        age = d.age;
        name = d.name;
    }
    friend void swap(Demo33&,Demo33&);
};

void swap(Demo33 &d1,Demo33 &d2){
    cout << "调用自己默认重载版本swap" << endl;
    using std::swap;
    swap(d1.name,d2.name);
    swap(d1.age,d2.age);
}

void test15(){
    Demo33 d1(1,"xx");
    Demo33 d2(2,"xxxx");
    using std::swap;
    swap(d1,d2);
}




class SreVec{
public:
    SreVec() : elements(nullptr),first_free(nullptr),cap(nullptr) {}
    SreVec(const SreVec&);  // 拷贝构造
    SreVec& operator=(const SreVec&);  // 拷贝赋值运算符
    ~SreVec();  // 析构

    void push_back( const string&);  // 压栈操作
    size_t size() const {
        return first_free - elements;
    }
    size_t capacity() const{
        return cap - elements;
    }
    string* begin() const{
        return elements;
    }
    string* end() const{
        return first_free;
    }

private:
    allocator<string> alloc;
    // 保证有新元素容纳空间
    void chk_n_alloc(){
        if (size() == capacity())
            reallocate();
    }
    // 不太知道
    pair<string*,string*> alloc_n_copy(const string*,const string*);
    void free();  // 销毁元素并释放内存
    void reallocate();  // 获得更多内存并拷贝已有元素

    string *elements;  // 数组首元素指针
    string *first_free;  // 数组第一个空闲的指针
    string *cap;   // 数组最后位置指针
};
void SreVec::push_back(const string &s) {
    chk_n_alloc();
    alloc.construct(first_free++,s);
}
pair<string*, string*> SreVec::alloc_n_copy(const string *a, const string *b) {
    auto data = alloc.allocate(b - a);
    return {data, uninitialized_copy(a,b,data)};
}

void SreVec::free() {
    if (elements){
        for(auto p = first_free;p != elements;)    // 1. destory 元素
            alloc.destroy(--p);
        alloc.deallocate(elements,cap - elements);   // 2. 释放SreVec自己分配的空间
    }
}
SreVec::SreVec(const SreVec &s) {
    auto newData = alloc_n_copy(s.begin(),s.end());
    elements = newData.first;
    first_free = newData.second;
}
SreVec::~SreVec() {
    free();
}

SreVec &SreVec::operator=(const SreVec &s) {
    auto data = alloc_n_copy(s.begin(),s.end());
    free();
    elements = data.first;
    first_free = data.second;
    return *this;
}

void SreVec::reallocate() {
    auto newCapacity = size() ? 2 * size() : 1;
    auto newData = alloc.allocate(newCapacity);
    auto dest = newData;
    auto elem = elements;
    for(size_t i = 0;i != size(); ++ i){
        alloc.construct(dest++,*elem++);
    }
    free();
    elements = newData;
    first_free = dest;
    cap = elements + newCapacity;
}

void test19(){
    SreVec sreVec;
    sreVec.push_back("hello");
    sreVec.push_back("jar");

    SreVec s2 = sreVec;
    auto p = s2.begin();
    while (p != s2.end()){
        cout << *p ++ << endl;
    }
}


void test17(){
    allocator<string> allocator;
    auto p = allocator.allocate(10);
    allocator.construct(p,"hello");

    cout << *p << endl;
}

void main1(){
    test19();
//    test17();
//    test15();
//    test11();
//    test10();
//    test08();
//    test06();
//    test05();
//    test04();
//    test03();
//    test02();
//    test01();
}
