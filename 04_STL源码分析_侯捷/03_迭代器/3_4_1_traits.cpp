//
// Created by 肖应雄 on 2021/12/28.
//

#include <iostream>
using namespace std;

/**
 *  与偏特化结合
 *  这一p侯捷讲的巨好    p15
 */

/**
 * 1. 问题1
 * traits 如何得到迭代器所指向的类别
 * 只能推导参数 无法推导类别
 *
 * 2. 几个术语的描述
 * what is value_type ?     Itertor 所指的值的type
 * what is difference_type ?    itertor 距离的值的类型   int ？  or  others   or unsingninter ？
 * what is itertor_category ?     迭代器类型  只能单步走 ？  只能++  只能--
 *
 *
 * 3. 问题3
 * class 类 很容易就可以推导出类型   T::vaule_type
 * 那要是指针呢 ？  指针传入算法中 怎么推导推类型？  traits！
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