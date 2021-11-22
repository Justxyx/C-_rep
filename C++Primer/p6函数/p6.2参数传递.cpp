//
// Created by 肖应雄 on 2021/11/19.
//

#include <iostream>
#include <array>

using namespace std;
#include "list.h"


//6.10
void swap_main2(int *a,int *b) {
    int *temp = a;
    *a = *b;
    *b = *temp;
}
void test610(){
    int a = 12;
    int b = 13;
    swap_main2(&a, &b);
    cout << a << endl;
}

//6.11
void swap_test611(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}
void test611(){
    int a = 1,b = 12;
    swap_test611(a,b);
    cout << a << endl;
    cout << b << endl;
}

//6.15
void find_char(const string &str,char c,string::size_type &count){
    auto size = str.size();
    count = 0;
    for (auto i = 0;  i != size ; i++) {
        if(str[i] == c){
            ++ count;
        }
    }
}
void test615(){
    string s = "hello word";
    string::size_type count_i ;
    char c = 'o';
    find_char(s, c, count_i);
    cout << count_i << endl;
}

//6.151 // const 指针问题
void test6151(){
//    const int i = 12;
//    const int &j = i;  // 引用必须初始化
//    j = 43;  错误 对常量的引用不可更改
//    int &j2 = i;   错误 非常量引用指向常量对象

//    int errNum = 0;
//    int * const p = &errNum;  // p指针不再改变
//    int errBug = 1;
//    const int *p1 = &errBug;   // p1 指针内容不再改变

//    const int i = 5;
//    constexpr int j = i;

    class User{
    public:
        int age;
    };


}

//6.16
bool isEmpty(const string& str){
    return str.empty();
}
void test616(){
    const string s1 = "hello word";
    bool  b =  isEmpty(s1);
    cout << b << endl;
}

//6.17

//数组形参问题
void print(const int *p){

}
void print1(const int p[],int size){

}
void print2(const int *start,const int *end){

}
void print3(int (&arr)[10]){

}
void test6171(){

}

//6.21
int method621(const int i,const int *j){
    return i>*j ? i:*j;
}
void test621(){
    int i = 12;
    int j = 21;
    int res = method621(i,&j);
    cout << res << endl;
}

//6.22
void method622(int* &p1,int* &p2){
    int *temp = p1;
    p1 = p2;
    p2 = temp;
}
void test622(){
    int i = 12,j = 22;
    auto p1 = &i;
    auto p2 = &j;
    cout << p1 << " --- " << p2 << endl;
    method622(p1,p2);
    cout << p1 << " --- " << p2 << endl;
}

//6.24
void method624(const int (&a)[10]){
    for (int i = 0; i < 10; ++i) {
        cout << a[i] << endl;
    }
}
void test624(){
    int a[10] = {1,2,4,5,1,1,1,1,11,1};
    method624(a);
}

//数组传参问题再详解
void method6241(int *p,int size){
    while (size > 0){
        cout << *p ++ << endl;
        --size ;
    }
}
void test6241(){
    int a[10] = {1,2,4,5,1,1,1,1,11,1};
    method6241(a,10);
}


//6.25
void main625( const int size,char arr[]){
    int i = 0;
    while ( i < size){
        cout << *arr++ << endl;
        ++ i;
    }
}
void test625(){
    char s [10] = {'a','b'};
    main625(2,s);
}

// 6.27
int method627(initializer_list<int> const &li){
    int sum;
    for(auto i : li) sum += i;
    return sum;
}
void test627(){
    auto list = {1,2,2,3,1,4,1,4,5,1,2};
    cout <<  method627(list) << endl;
}

// 6.31
const string& method631(const string& str){
//    cout << str << endl;
    string s = "hello";
    return s;
}
void test631(){
    string str = "hello mi";
    string st = method631(str);
    cout << st << endl;
}

//6.32 左值问题
int& method632(int* arr,int index){
    return arr[index];
}
void method6321(const string& str){
    for (int i = 0; i <str.size(); ++i) {
        cout << str[i] << endl;
    }
}
void test632(){
    int a[10];
    for (int i = 0; i < 10; ++i) {
        method632(a,i) = i;
    }
    for (const auto &item : a) cout << item;
    method6321("hello word");
}

// 6.36  数组指针问题
void method6361(){
    int arr[10];  // 十个整数的数组
    int* arr1[10];  // 十个指针的数组
    int (*arr2)[10] = &arr;   // 一个指针，指向十个整数的数组。

    // 2. 尾置返回类型
    auto func(int i) -> int(*) [10];

    //3. decltype
    int a[10] ={};
    int b[10] ={};
    decltype(a)* method();
}
void method636(){
    string str[10];
    auto func1() -> string(&) [10];
    decltype(str)& func2();

}

//639 函数重载问题 重载与const问题
class demo{

};

//以下四种表达 无法重载  顶层const
//void method639(demo demo){
//}
//void method639(const demo demo){
//}

//void method639(demo* demo){
//}
//void method639(demo* const demo){
//}
//关于顶层const问题 顶层const 指针内地址不可变
//void method639(demo* const demo){
//    class demo d2;
////    demo = &d2;  错误
//}

//   ** 底层const 与 引用 是可以区分重载的**
void method639(demo& d){
    cout << " 非常量函数 " << endl;
}

void method639(const demo& d){
    cout << " 常量函数 " << endl;
}
void method6391(demo* demo){
    cout << "指针 非常量函数" << endl;
}
void method6391(const demo* demo){

    cout << "指针 常量函数" << endl;
}
void test639(){
    demo d1;
    const demo d2;
//    method639(d1);
//    method639(d2);

    demo* p = &d1;
    method6391(p);
    method6391(&d2);

}

// 646 constexpr函数
constexpr int mt(){
    return 22;
}
constexpr int method646(int i){
    return 22*mt();
}
void test646(){
    int j = 10;
    int arr[10];
    int arr1[method646(10)];
    int arr2[method646(j)];
}
/**
 *  constexpr修饰的函数，简单的来说，如果其传入的参数可以在编译时期计算出来，那么这个函数就会产生编译时期的值。
 *  但是，传入的参数如果不能在编译时期计算出来，那么constexpr修饰的函数就和普通函数一样了。
 *  不过，我们不必因此而写两个版本，所以如果函数体适用于constexpr函数的条件，
 *  可以尽量加上constexpr。而检测constexpr函数是否产生编译时期值的方法很简单，
 *  就是利用std::array需要编译期常值才能编译通过的小技巧。这样的话，即可检测你所写的函数是否真的产生编译期常值了。
 */

using namespace std;
constexpr int foo(int i)
{
    return i + 5;
}

int main222()
{
    int i = 10;
    array<int, foo(5)> arr; // OK

    foo(i); // Call is Ok

    // But...
//    array<int, foo(i)> arr1; // Error  数组的初始化要用常量表达式

}

void main2(){
    test646();
//    test639();
//    test632();
//    test631();
//    test627();
//    test625();
//    test6241();
//    test624();
//    test622();
//    test610();
//    test611();
//    test615();
//    test616();
//    test621();
}