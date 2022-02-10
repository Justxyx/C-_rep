//
// Created by 肖应雄 on 2022/1/5.
//

#include <cstdio>

/**
 * 基本结构如下
 * @tparam T
 * @tparam Alloc
 */
template<class T,class Alloc = alloc>
class vector_s{
public:
    typedef T value_type;
    typedef value_type* iterator;       // 指针就是迭代器  不用再用class 包一个迭代器
    typedef value_type& reference;
    typedef size_t size_type;
protected:
    iterator start;
    iterator finish;
    iterator end_of_storage;
public:
    iterator begin(){
        return start;
    }
    iterator end(){
        return finish;
    }
    iterator size() const{
        return size_type (end() - begin());    // 为什么不直接  finish - start?
    }
    iterator capacity() const{
        return size_type (end_of_storage - begin());
    }
    bool empty() const{
        return begin() == end();
    }
    reference operator[](size_type n){     // 所有连续空间 都必须提供[] 小括号随机访问  deque也有
        return *(begin() + n);
    }
    reference front(){
        return *begin();
    }
    reference back(){
        return *(end() - 1);
    }


};

