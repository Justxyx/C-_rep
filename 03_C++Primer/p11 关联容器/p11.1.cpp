//
// Created by 肖应雄 on 2021/11/29.
//
#include <iostream>
#include <map>
#include <set>
#include <vector>


using namespace std;

void test01(){
    map<string,size_t> word_count ;
    set<string> word_exclude = {"aa","a","aaa"};
    string word;
    while(cin >> word && word != "xx"){
        if (word_exclude.find(word) == word_exclude.end())
            ++word_count[word];
    }
    for (const auto &item : word_count)
        cout << item.first << "：出现了" << item.second << "次";
}

void test02(){
    vector<int> v;
    for (vector<int>::size_type i= 0;  i<10 ; ++i) {
        v.push_back(i);
        v.push_back(i);
    }
    set<int> iset(v.begin(),v.end());
    multiset<int> miset(v.begin(),v.end());

    cout << v.size() << endl;     // 20
    cout << iset.size() << endl;    // 10
    cout << miset.size() << endl;   // 20
}




void test03(){
    multiset<int> s = {1,4,2,3,5,6,2};
    for (const auto &item : s)
        cout << item << " " ;    // 1 2 2 3 4 5 6  set 为有序集合
    multimap<int,int> m = {
            {1,3},
            {2,4},
            {5,3},
            {3,4}
    };
    for (const auto &item : m){
        cout << item.first << ":" << item.second << " ";   // 1:3 2:4 3:4 5:3   map 也是按照关键字排序
    }
}

pair<string,int> process(vector<string> &v){
    if ( ! v.empty())
        return {v.back(),v.back().size()};   // 列表初始化
    else
        return pair<string,int>();      // 隐式构造返回值
}

void test04(){
    vector<string> v = {"hello" , "hey"};
    pair<string,int> p =  process(v);
    cout << p.first << "  " << p.second << endl;
}

void test05(){
    map<int,string> iMap = {
            {1, "jay"},
            {2,"chou"},
            {3,"may"}
    };
    set<int> iSet = {1,3,2,5,4,5};

    auto c = iMap.cbegin();
    while (c != iMap.cend()){
        cout << c->first << endl;
        ++ c;
    }
}

void test06(){
    map<int,string> iMap = {
            {1, "jay"},
            {2,"chou"},
            {3,"may"}
    };
    set<int> iSet = {1,3,2,5,4,5};

    auto res = iMap.insert(pair<int,string>(2,"xx"));
    cout << res.first->second << endl;   // 返回迭代器
    cout << res.second << endl;           // 返回 bool 值 是否插入成功

}

void test07(){
    map<int,string> iMap = {
            {1, "jay"},
            {2,"chou"},
            {3,"may"}
    };
    set<int> iSet = {1,3,2,5,4,5};
    auto b =  iMap.erase(1);   // b为删除数量
    auto p = iMap.begin();
    iMap.erase(p);      // 删除迭代器为p的元素 迭代器必须真实存在
    cout << b << endl;
}

void test08(){
    map<int,string> iMap = {
            {1, "jay"},
            {2,"chou"},
            {3,"may"}
    };

    cout << iMap[2] << endl;
    iMap[5] = "hey jay";
    cout << iMap[5] << endl;
    iMap.at(4);
}

void test09(){
    map<int,string> iMap = {
            {1, "jay"},
            {2,"chou"},
            {3,"may"}
    };
    if ( iMap.find(1) == iMap.end())
        cout << " has not found" << endl;
    else{
        auto p = iMap.find(1);   // 返回一个迭代器，如果没有该元素 则直接返回end迭代器。
        cout << p->second << endl;
    }
}


// 对于重复元素的查找
void test10(){
    multimap<int,string> iMap = {
            {1, "jay"},
            {1,"chou"},
            {1,"may"}
    };
    auto count = iMap.count(1);
    auto item = iMap.find(1);
//    1. 方法一
    while(count){
        cout << item ->second << endl;
        -- count ;
        ++ item;
    }
//    2.方法2
    for(auto begin = iMap.lower_bound(1),end = iMap.upper_bound(1);begin!=end;begin++)
        cout << begin->second << endl;
}

void main1(){
    test10();
//    test09();
//    test08();
//    test07();
//    test06();
//    test05();
//    test04();
//    test03();
//    test02();
//    test01();
}