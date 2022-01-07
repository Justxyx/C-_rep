//
// Created by 肖应雄 on 2022/1/7.
//

/*
*      - iterator
*          1. cur 指向当前buffer 位置
*          2. first buffer 头
*          3. last buffer 尾
*          4. node 指向map
 *
 *
 *          iterator 的四根指针
 *
 *          -1. 如何算迭代器距离？
 *          简单  buffer个数*size + 头尾buffer个数
 *
 *
 *
 *          特别奇怪的一点  deque为什么要设计成可以从中间插入的元素
 *
 *          queue 并不能从中间插入