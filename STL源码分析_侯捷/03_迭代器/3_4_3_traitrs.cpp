//
// Created by 肖应雄 on 2021/12/28.
//

/**
* traits 特化版本
*/

#include <iostream>
using namespace std;

template<class T>
struct itertor_traits{
    // 公共版本
};

template<class T>
struct itertor_traits<T*>{
    // 指针特化版本
};

template<class T>
struct itertor_traits<const T*>{
    // const 指针特化版本
};