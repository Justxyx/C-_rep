//
// Created by 肖应雄 on 2021/12/27.
//
#include <iostream>
using namespace std;
#include <string>

/**
 * 简化版的智能指针
 * @tparam T
 */

template<class T>
class auto_ptre{
public:
    /**
     * explicit关键字的作用就是防止类构造函数的隐式自动转换.
     * C++中的explicit关键字只能用于修饰只有一个参数的类构造函数,
     * @param p
     */
    explicit auto_ptre(T *p = 0): pointee(p){}

    template<class U>
    auto_ptre(auto_ptr<U> &rhs ):pointee(rhs.release()){};

    ~auto_ptre(){
        delete pointee;
    }

    template<class U>
    auto_ptr<T>& operator=(auto_ptr<U> &rhs){
        if  (this != &rhs)
            reset(rhs.release());
    }

    T& operator*() const{
        return *pointee;
    }
    T* operator->() const{
        return pointee;
    }
    T* get() const{
        return pointee;
    }


private:
    T *pointee;
};

int main321(){

    auto_ptre<string> p(new string("hello jay"));
    cout << p->data() << endl;
}