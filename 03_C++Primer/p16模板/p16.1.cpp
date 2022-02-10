//
// Created by 肖应雄 on 2021/12/6.
//
#include <iostream>
using namespace std;


//1. 函数模板
template<typename T,typename  K>
int method(const T &t,const K &k){
    return t > k ? 1 : 0;
}
void test01(){
    int i = method(1,2);
    cout << i << endl;
}

//2.模板类
template<typename T>
class Demo1{
public:
        T t;
        void print(Demo1<T> ){

        }


    };
template<typename> class Demo3;   // 模板声明
template<typename T>
class Demo2{
public:
    friend class Demo3<T>;
};

template<typename T>
class Demo3{
private:
    int i = 12;
    void print(){
        cout << i << endl;
    }
};


void main1(){
    test01();
}