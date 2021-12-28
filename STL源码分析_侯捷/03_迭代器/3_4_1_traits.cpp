//
// Created by 肖应雄 on 2021/12/28.
//

#include <iostream>
using namespace std;

/**
 * traits 如何得到迭代器所指向的类别
 * 只能推导参数 无法推导类别
 */

template<class T,class I>
void func_impl(T iter,I t){
    I tmp;   // 得到迭代器所指之物的类别

}

template<class T>
inline
void func(T iter){
    func_impl(iter,*iter);
}

int main341(){
    int i;
    func(&i);
}