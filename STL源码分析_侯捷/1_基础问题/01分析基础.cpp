//
// Created by 肖应雄 on 2021/12/27.
//

#include <iostream>
using namespace std;
#include <array>
#include "assist.h"
#include <vector>
#include <stdexcept>
#include <string>
#include <cstdlib>      // abort()
#include <cstdio>       // snprintf()
#include <iostream>
#include <ctime>
#include <algorithm>    // sort()
#include "assist.h"
#include <list>
#include <forward_list>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
namespace xm01{
    const long ASIZE = 500000;
    void test_array(){
        cout << "test_array()...." << endl;
        array<long,ASIZE> c;
        auto timeStart = clock();

        for(long i = 0; i < ASIZE ; ++i){
            c[i] = rand()%10000;
        }

        cout << "mills-seconds:" << (clock() - timeStart) << endl;
        cout << "array.size():" << c.size() << endl;
        cout << "array.front():" << c.front() << endl;
        cout << "array.back():" << c.back() << endl;
        cout << "array.data(): " << c.data() << endl;   // 0x16ec8ecc0

        long target = get_a_target();
        timeStart = clock();
        qsort(c.data(),ASIZE,sizeof(long), compare_longs);   // quick sort
        long *pItem = (long*)bsearch(
                &target,
                c.data(),
                ASIZE,
                sizeof(long),
                compare_longs
        );
        cout << "qsort()+bsearch(),:" << clock() - timeStart << endl;

        if (pItem != NULL){
            cout << "found: " << *pItem << endl;
        } else
        {
            cout << "not found" << endl;
        }
    }
}

/**
 * 02. vector 测试
 * 两个习惯养成：
 *      1. 变量顶格写 比较容易好找
 *      2. 用好namespace
 */
namespace xm02{
    void test_vector(long &value){
        cout << "test_vector.." << endl;
        vector<string> c;
        char buf[10];

        clock_t timeStart = clock();
        for(long i = 0; i < value ; ++ i){
            try{
                snprintf(buf,10,"%d",rand()%10000);
                c.push_back(string(buf));
            }catch(exception &p) {
                cout << "i = " << i << " " << p.what() << endl;
                abort();
            }
        }

        cout << "milli - seconds:" << clock() - timeStart << endl;
        cout << "size: " << c.size() << endl;
        cout << "front: " << c.front() << endl;
        cout << "back: " << c.back() << endl;
        cout << "data: " << c.data() << endl;
        cout << "capacity: " << c.capacity() << endl;

        string target = get_a_target_string();
        timeStart = clock();

//        1. find algorithm
        vector<string>::iterator pItem = ::find(c.begin(),c.end(),target);
        cout << "find time : " << clock() - timeStart << endl;
        if  ( pItem != c.end()){
            cout << "has found:" << *pItem << endl;
        } else{
            cout << "not found" << endl;
        }

//        2. 二分查找
        timeStart = clock();
        sort(c.begin(),c.end());
        string* pIt = (string*) bsearch(
                &target,
                c.data(),
                c.size(),
                sizeof(string),
                compare_strings
        );
        cout << "bsearch found time :" << clock() - timeStart << endl;
        if  ( pIt != nullptr){
            cout << "has found:" << *pIt << endl;
        } else{
            cout << "not found" << endl;
        }
    }

    void main(){
        long i = 100000;
        test_vector(i);
    }
}

/**
 * list  双向队列
 */
namespace xm03{
    void test_list(long &value){
        list<string> c;
        char buf[10];
        clock_t timeStart = clock();
        for(long i = 0;i < value ; ++i){
            try{
                snprintf(buf,10,"%d",rand()%10000);
                c.push_back(string(buf));
            }catch(exception &p) {
                cout << "index out " <<  p.what()<< endl;
                abort();
            }
        }
        cout << "milli - seconds:" << clock() - timeStart << endl;
        cout << "size: " << c.size() << endl;
        cout << "front: " << c.front() << endl;
        cout << "back: " << c.back() << endl;
        cout << "max size:" << c.max_size() << endl;

        string target = get_a_target_string();
        timeStart = clock();
        list<string>::iterator pItem = ::find(c.begin(),c.end(),target);
        cout << "find time is :" << timeStart - clock() << endl;
        if  (pItem != c.end()){
            cout << "has found :" << *pItem << endl;
        }else{
            cout << "has not found" << endl;
        }

        timeStart = clock();
        c.sort();
        cout << "sort has spand :" << timeStart - clock() << "mils" << endl;
    }
    void main(){
        long target = 1000000;
        test_list(target);
    }
}

/**
 * forward_list  单向队列
 */
namespace xm04{
    void test_forward_list(long &value){
        forward_list<string> c;
        char buf[10];
        clock_t timeStart = clock();
        for(long i = 0;i < value ; ++i){
            try{
                snprintf(buf,10,"%d",rand()%10000);
                c.push_front(string(buf));
            }catch(exception &p) {
                cout << "index out " <<  p.what()<< endl;
                abort();
            }
        }
        cout << "milli - seconds:" << clock() - timeStart << endl;
        cout << "front: " << c.front() << endl;
        cout << "max size:" << c.max_size() << endl;

        string target = get_a_target_string();
        timeStart = clock();
        forward_list<string>::iterator pItem = ::find(c.begin(),c.end(),target);
        cout << "find time is :" << clock() - timeStart << endl;
        if  (pItem != c.end()){
            cout << "has found :" << *pItem << endl;
        }else{
            cout << "has not found" << endl;
        }

        timeStart = clock();
        c.sort();
        cout << "sort has spand :" << clock() - timeStart<< "mils" << endl;
    }
    void main(){
        long target = 1000000;
        test_forward_list(target);
    }
}


/**
 * forward_list  单向队列
 */
namespace xm05{
    void test_deque(long &value){
        deque<string> c;
        char buf[10];
        clock_t timeStart = clock();
        for(long i = 0;i < value ; ++i){
            try{
                snprintf(buf,10,"%d",rand()%10000);
                c.push_front(string(buf));
            }catch(exception &p) {
                cout << "index out " <<  p.what()<< endl;
                abort();
            }
        }
        cout << "milli - seconds:" << clock() - timeStart << endl;
        cout << "front: " << c.front() << endl;
        cout << "back:" << c.back() << endl;
        cout << "size:" << c.size() << endl;
        cout << "max size:" << c.max_size() << endl;

        string target = get_a_target_string();
        timeStart = clock();
        deque<string>::iterator pItem = ::find(c.begin(),c.end(),target);
        cout << "find time is :" << clock() - timeStart << endl;
        if  (pItem != c.end()){
            cout << "has found :" << *pItem << endl;
        }else{
            cout << "has not found" << endl;
        }

        timeStart = clock();
        ::sort(c.begin(),c.end());
        cout << "sort has spand :" << clock() - timeStart<< "mils" << endl;
    }
    void main(){
        long target = 1000000;
        test_deque(target);
    }
}

/**
 * multiset  允许放重复值
 * 没必要sort
 * 插入慢 查找快 空间小
 */
namespace xm06{
    void test_multiset(long &value){
        multiset<string> c;
        char buf[10];
        clock_t timeStart = clock();
        for(long i = 0;i < value ; ++i){
            try{
                snprintf(buf,10,"%d",rand()%10000);
                c.insert(string(buf));
            }catch(exception &p) {
                cout << "index out " <<  p.what()<< endl;
                abort();
            }
        }
        cout << "milli - seconds:" << clock() - timeStart << endl;
        cout << "size:" << c.size() << endl;
        cout << "max size:" << c.max_size() << endl;

        string target = get_a_target_string();
        timeStart = clock();
        multiset<string>::iterator pItem = ::find(c.begin(),c.end(),target);
        cout << "find time is :" << clock() - timeStart << endl;
        if  (pItem != c.end()){
            cout << "has found :" << *pItem << endl;
        }else{
            cout << "has not found" << endl;
        }


    }
    void main(){
        long target = 1000000;
        test_multiset(target);
    }
}
/**
 * multimap  允许放重复值
 *
 * 插入慢 查找快 空间小
 */
namespace xm07{
    void test_multimap(long &value){
        multimap<long,string> c;
        char buf[10];
        clock_t timeStart = clock();
        for(long i = 0;i < value ; ++i){
            try{
                snprintf(buf,10,"%d",rand()%10000);
                c.insert(pair<long,string>(i,string(buf)));
            }catch(exception &p) {
                cout << "index out " <<  p.what()<< endl;
                abort();
            }
        }
        cout << "milli - seconds:" << clock() - timeStart << endl;
        cout << "size:" << c.size() << endl;
        cout << "max size:" << c.max_size() << endl;

        string target = get_a_target_string();
        timeStart = clock();
        auto pItem =  c.find(1345);
        cout << "find time is :" << clock() - timeStart << endl;
        if  (pItem != c.end()){
            cout << "has found :" << pItem->second << endl;
        }else{
            cout << "has not found" << endl;
        }


    }
    void main(){
        long target = 1000000;
        test_multimap(target);
    }
}

/**
 * unordered_set   hash set
 * 插入查找都挺快  就是空间有点大   桶的个数比数据个数要大
 */
namespace xm08{
    void test_multiset(long &value){
        unordered_set<string> c;
        char buf[10];
        clock_t timeStart = clock();
        for(long i = 0;i < value ; ++i){
            try{
                snprintf(buf,10,"%d",rand()%10000);
                c.insert(string(buf));
            }catch(exception &p) {
                cout << "index out " <<  p.what()<< endl;
                abort();
            }
        }
        cout << "milli - seconds:" << clock() - timeStart << endl;
        cout << "size:" << c.size() << endl;
        cout << "max size:" << c.max_size() << endl;
        cout << "bucker_count" << c.bucket_count() << endl;   // 桶的个数
        cout << "load_factor:" << c.load_factor() << endl;    // 装载因子问题
        cout << " max bucker_count" << c.max_bucket_count() << endl;   // 最大桶的个数
        cout << "max load_factor:" << c.max_load_factor() << endl;    // 最大装载因子问题

        string target = get_a_target_string();
        timeStart = clock();
        auto pItem = ::find(c.begin(),c.end(),target);
        cout << "find time is :" << clock() - timeStart << endl;
        if  (pItem != c.end()){
            cout << "has found :" << *pItem << endl;
        }else{
            cout << "has not found" << endl;
        }


    }
    void main(){
        long target = 1000000;
        test_multiset(target);
    }
}

/**
 * unordered_map  hash 结构 查找快
 */
namespace xm09{
    void test_multimap(long &value){
        unordered_map<long,string> c;
        char buf[10];
        clock_t timeStart = clock();
        for(long i = 0;i < value ; ++i){
            try{
                snprintf(buf,10,"%d",rand()%10000);
                c.insert(pair<long,string>(i,string(buf)));
            }catch(exception &p) {
                cout << "index out " <<  p.what()<< endl;
                abort();
            }
        }
        cout << "milli - seconds:" << clock() - timeStart << endl;
        cout << "size:" << c.size() << endl;
        cout << "max size:" << c.max_size() << endl;
        cout << "bucker_count" << c.bucket_count() << endl;   // 桶的个数
        cout << "load_factor:" << c.load_factor() << endl;    // 装载因子问题
        cout << " max bucker_count" << c.max_bucket_count() << endl;   // 最大桶的个数
        cout << "max load_factor:" << c.max_load_factor() << endl;    // 最大装载因子问题

        string target = get_a_target_string();
        timeStart = clock();
        auto pItem =  c.find(1345);
        cout << "find time is :" << clock() - timeStart << endl;
        if  (pItem != c.end()){
            cout << "has found :" << pItem->second << endl;
        }else{
            cout << "has not found" << endl;
        }


    }
    void main(){
        long target = 1000000;
        test_multimap(target);
    }
}

/**
 * 泛化与特化问题
 */
namespace xm10{
    template<class T>
    class type_traits{
        /**
         * 泛化
         */
    };
    template<> class type_traits<int>{
        /**
         * 特化1
         */
    };
    template<> class type_traits<double>{
        /**
         * 特化1
         */
    };
}

/**
 * 泛化与偏特化问题
 */
namespace xm11{
//    1. 偏特化1
    template<class T,class alloc = int>
    class type_traits{
        /**
         * ....
         */
    };
    template<class alloc>
    class type_traits<bool,alloc>{
        /**
         * 偏特化问题
         * 如果是bool值的话，指定为该模板
         */
    };
//    ---------------------------------------
    template<class T>
    class demo{
        /**
         * ...
         */
    };
    template<class T>
    class demo<T*>{
        /**
         * 偏特化
         * 指定为指针
         */
    };
    template<class T>
    class demo<const T*>{
        /**
         * 偏特化
         * 指定为const 指针
         */
    };
}

int main01(){
//    xm01::test_array();
//    xm02::main();
//    xm03::main();
//    xm04::main();
//    xm05::main();
//    xm06::main();
//    xm07::main();
//    xm08::main();
//    xm09::main();
}