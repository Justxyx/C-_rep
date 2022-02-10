//
// Created by 肖应雄 on 2021/12/23.
//
#include <iostream>
using namespace std;
#include <vector>
#include <list>
// 反向迭代器问题
namespace xm01{
    void test01(){
        vector<int> c;
        for(int i = 0;i< 1000; ++i){
            c.push_back(i);
        }
        cout << *c.begin() << endl;
        cout << *--c.end() << endl;

    }
    void main(){
        test01();
    }
}

/**
 * 赋值  swap
 */
namespace xm02{
    void method01(){
        list<int> c{1,2,3,4,5,6};
        list<int> c2{5,3,1,2};
//        c = c2;    // c2 的值完全赋值给c1
//        for (const auto &item : c)   // 5,3,1,2,
//            cout << item << ",";
        c.swap(c2);    // swap 比赋值要快的多
        for (const auto &item : c)   // 5,3,1,2,
            cout << item << ",";
    }
    void method2(){
        list<int> c{1,2,3,4,5,6};
        list<int> c1;
        c1.assign(c.begin(),--c.end());
        for (const auto &item : c1)
            cout << item << ",";
    }
    void main(){
//        method01();
        method2();
    }
}


int main(){
//    xm01::main();
    xm02::main();
}