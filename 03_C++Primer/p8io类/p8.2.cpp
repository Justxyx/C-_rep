//
// Created by 肖应雄 on 2021/11/24.
//

using namespace std;
#include "list.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


void method81(const string& fileNmae,vector<string>& vec){
    ifstream ifs(fileNmae);
    if(ifs){
        string buf;
        while(getline(ifs,buf)){
            vec.push_back(buf);
        }
    }
}
// 单词独立存储
void method82(const string& fileNmae,vector<string>& vec){
    ifstream ifs(fileNmae);
    if(ifs){
        string buf;
        while(ifs>>buf){
            vec.push_back(buf);
        }
    }
}
void test81(){
    vector<string> vec;
    method82("/Users/xiaoyingxiong/projects/ClionProjects/Cpp_rep/C++Primer/p8io类/a.txt",vec);
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << endl;
    }
}

void main2(){
    test81();
}