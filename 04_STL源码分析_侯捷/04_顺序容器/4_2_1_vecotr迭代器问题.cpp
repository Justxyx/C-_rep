//
// Created by 肖应雄 on 2021/12/29.
//
#include <iostream>
using namespace std;
#include <vector>

/**
 * 写点笔记:
 *      vector 动态增加大小，并不是在原有的基础上续接空间的。
 *      一旦空间位置重新分配，原来指向vector的指针迭代器就失效了！！！！！！
 *      只要是连续的空间 就可以使用自身的指针作为迭代器
 *      vector的迭代器就是自身的指针 所以 要用到traits
 */
template<class T>    // traits 的指针特化版本
struct iterator_traits<T*>{
    typedef random_access_iterator_tag iterator_category;
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef T* pointer;
    typedef T& reference;
};






int main421(){
    vector<int> v(10,12);
    vector<int>::iterator p = v.begin();
    cout << *p << endl;
    for (int i = 0; i < 1000; ++i) {
        v.push_back(i);
    }
    cout << *p << endl;   //  迭代器已经失效
}