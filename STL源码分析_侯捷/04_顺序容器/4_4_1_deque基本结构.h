//
// Created by 肖应雄 on 2021/12/30.
//

#ifndef STL__4_4_1_DEQUE基本结构_H
#define STL__4_4_1_DEQUE基本结构_H

/**
 *  一点笔记：
 *      1. deque 没有所谓的容量的概念
 *      2. 为了提高效率 可以先将deque复制到vector中，再排序
 *      3. deque 是有迭代器的
 */

/**
template<class T,class Alloc , class size_t >
class deque{
public:
    typedef T value_type;
    typedef value_type* pointer;
protected:
    typedef pointer* map_pointer;
protected:
    map_pointer map;
    size_type map_size;
};
**/






#endif //STL__4_4_1_DEQUE基本结构_H
