//
// Created by 肖应雄 on 2021/12/30.
//

#include <cstdio>
#include <iostream>
#include <deque>
#include <queue>

using namespace std;

#ifndef STL__4_4_1_DEQUE基本结构_H
#define STL__4_4_1_DEQUE基本结构_H

/**
 *  一点笔记：
 *      1. deque 没有所谓的容量的概念
 *      2. 为了提高效率 可以先将deque复制到vector中，再排序
 *      3. deque 是有迭代器的   双向开口que   分段连续
 *      4. 不太理解 为什么deque 可以支持随机访问
 */
int main() {
    deque<int> q(10,1);
    queue<int,deque<int>> q2(q);   // queue 构造
    cout << q[2] << endl;   // deque 支持随机访问
//    cout << q2[2] << endl;   // queue 不支持支持随机访问
    return 0;
}
/**
 * 基本结构：
 *      - map
 *          1. map 为控制中心   实际上是一个vector
 *      - buffer
 *          1. buffer 为分块
 *      - iterator
 *          1. cur 指向当前buffer 位置
 *          2. first buffer 头
 *          3. last buffer 尾
 *          4. node 指向map
 */


// 迭代器
template <class T,class Ref,class Ptr,size_t BufSize>
struct __deque_iteraotr{
    typedef random_access_iterator_tag iterator_category ;    // 迭代器是可以跳转的 random_access
    typedef T value_type;
    typedef Ptr pointer;
    typedef Ref reference;
    typedef size_t  size_type;    //  数组长度
    typedef ptrdiff_t difference_type;  //  指针长度
    typedef T** map_pointer;
    typedef __deque_iteraotr self;

    // 数据区
    T* cur;
    T* first;
    T* last;
    map_pointer node;
};


/**
 * 1. BufSize 默认为0 ，如果不指定BufSize ， 则自动分配 （512/sizeof)
 */
// deque 结构
template<class T,class Alloc = alloc, size_t BufSize=0>
class deque{
public:
    typedef T value_type;
    typedef __deque_iteraotr<T,T&,T*,BufSize> iterator;
protected:
    typedef pointer* map_pointer;  // T**
protected:
    iterator start;
    iterator finish;
    map_pointer map;
    size_type map_size;
public:
    iterator begin(){
        return start;
    }
    iterator end(){
        return finish;
    }
    iterator size() const{
        return (finish - start);
    }
};





#endif //STL__4_4_1_DEQUE基本结构_H
