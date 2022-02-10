//
// Created by 肖应雄 on 2022/1/5.
//



#include <iostream>
using namespace std;
#include <vector>


void push_back(const T &x){
    if(finish != end_of_storage){
        construct(finish,x);
        ++ finish;
    }
    else{
        // 调用新的空间
        insert_auc(finish,x);
    }
}

void insert_auc(iterator position,const T &x){
    if( finish != end_of_storage){
        // 还有空间
        construct(finish,*(finish -1));
        ++finish;
        T x_copy = x;
        copy_backward(position,finish - 2 ,finish -1 );
        *position = x_copy;
    }
    else{
        // 无空间

        /**
         * 1. 如果原来的size为0  则 新size 为 1
         * 2. 如果 不为 0  两倍
         * 3. 申请空间 拷贝
         * 4. 注意一点：   拷贝是会将 start 到 posion ，以及 posion  到 finsih 的空间都拷贝过去。
         *     之所以这么做，是为了拷贝算法的通用性。
         */
    }
}