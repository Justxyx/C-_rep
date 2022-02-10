//
// Created by 肖应雄 on 2022/1/5.
//

iterator insert(iterator position,const value_type &x){
    if(position == start)
        push_front(x);
    if(position == finish)
        push_back(x);
    else{
        // 调用函数 insert_aux；
        insert_aux();
    }
}

void insert_aux(){
    // 分别往前 和往后找 看position离哪一端比较近 就移动哪一端
}