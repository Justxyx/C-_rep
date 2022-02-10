//
// Created by 肖应雄 on 2021/12/28.
//

/**
 * list 迭代器的实现
 */

#ifndef STL__3_2_4_MYLISTITER_H
#define STL__3_2_4_MYLISTITER_H

template<class Item>
struct ListIter{
    Item *ptr;

    ListIter(Item *ptr) : ptr(ptr) {}

    Item& operator*()const{
        return *ptr;
    }

    Item* operator->() const{
        return ptr;
    }

    // 前++
    ListIter& operator++(){
        ptr = ptr->next;
        return *this;
    }

    // 后 ++
    ListIter operator++(int){
        ListIter temp = *this;
        ++*this;   // 调用前++
        return temp;
    }
    /**
     * 为什么前++ 要返回引用  后++ 不返回引用？
     * stl就是这么设计的
     * ++++i  成立
     * i++++  不成立
     */



    bool operator==(const ListIter &i)const {
        return ptr == i.ptr;
    }

    bool operator!=(const ListIter &i)const {
        return ptr != i.ptr;
    }
};


#endif //STL__3_2_4_MYLISTITER_H


