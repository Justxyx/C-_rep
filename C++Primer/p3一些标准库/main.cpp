#include <iostream>
#include <vector>

using namespace std;

//1.string
namespace p1{
//    1. string size 问题
    void test01(){
        string s1 = "hello jay";
        string s2 = "xxx";
        if (s1 == s2){
            cout << "yes" << endl;
        }else {
            cout << "no" << endl;
        }

        string s3 ;
        cout << s3.empty() << endl;

        // size 所返回的类型为无符号数。 切记
        if (s2.size() < -1){
            cout << "xm" << endl;
        }
    }

    void test02(){
        string str = "hey mimi";
        decltype(str.size()) count = 0;
        for (const char &item : str){
            if (isalnum(item)){
                count ++;
            }
            cout <<  count << endl;
        }
    }

    void test03(){
        string str = "hello xm";
        if ( !str.empty()){
            str[0] = toupper(str[0]);
        }
        cout << str << endl;
    }

    void ma(){
//        test01();
//        test02();
        test03();
    }
}

//2. 容器
namespace p2{

    void test01(){
        vector<int> vec(10);
        cout << vec[1] << endl;
    }

    void ma(){
        test01();
    }

}

//3. 迭代器问题
namespace p3{
    void test01(){
        string str = "hey mi";
        for(auto it = str.begin();it != str.end();it++){
            cout << *it << endl;
        }
    }
    void ma(){
        test01();
    }
}

//4. 数组问题
namespace p4{
//    1. 数组遍历
    void test01(){
        int a[5] ;
        for (auto &item : a){
            cout << item << endl;
        }
    }

//    2. 数组与指针
    void test02(){
        int arr[10] ;
        for (int i = 0; i < 10; ++i) {
            arr[i] = i;
        }

//        int* p = arr;
//        int* end = &arr[10];

        int* p = begin(arr);
        int* en = end(arr);
        cout << p   << endl;
        cout << &arr[0] << endl;
    }

    void ma(){
        test02();
//        test01();
    }
}

int main() {
//    p1::ma();
//    p2::ma();
//    p3::ma();
    p4::ma();
    return 0;
}
