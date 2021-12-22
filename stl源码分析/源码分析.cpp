//
// Created by 肖应雄 on 2021/12/22.
//

/**
 * 01.array算法测试  sort 与 二分查找
 */
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



int main(){
//    xm01::test_array();
    xm02::main();
}