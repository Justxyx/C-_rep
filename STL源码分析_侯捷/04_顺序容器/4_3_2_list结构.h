//
// Created by 肖应雄 on 2021/12/29.
//

#ifndef STL__4_3_2_LIST结构_H
#define STL__4_3_2_LIST结构_H

/**
 * 一点笔记 ：
 *
 *      list 的插入与删除不会影响迭代器的指向
 *      这跟vector还是有很大区别的
 * @tparam T
 */


#include <cstdio>

/**
 * 节点结构
 */
template<class T>
struct __list_node{
    typedef void* void_pointer;
    void_pointer prev;
    void_pointer next;
    T data;
};

/**
 * list 迭代器设计
 */
template<class T,class Ref,class Ptr>
struct __list_iterator{
    typedef __list_iterator<T,T&,T*> itrator;
    typedef __list_iterator<T,Ref,Ptr> self;

    typedef T value_type;
    typedef Ptr pointer;
    typedef Ref reference;
    typedef __list_node<T>* link_type;
    typedef size_t size_type;
};


#endif //STL__4_3_2_LIST结构_H
