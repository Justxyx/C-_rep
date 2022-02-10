//
// Created by 肖应雄 on 2021/12/28.
//

/**
 * 这个编译总是报错
 * 推导返回值
 */

#include <iostream>
using namespace std;

template <class T>
struct MyIter {
    typedef T value_type; // 内嵌型别声明
    value_type* i;

    MyIter(value_type *i) : i(i) {}
    // ...
};

template <class I>
typename I::value_type
func(I ite) {
    return *ite;
}

// ...
int main342(){
    MyIter<int> ite(new int(8));

}
