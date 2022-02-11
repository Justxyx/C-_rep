#include <iostream>
#include <string>
using namespace std;
#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <list>

/**
 * 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
 * @return
 */


class Solution {
public:
    string replaceSpace(string s) {
        list<char> list;
        for (const auto &item : s){
            if ( item == ' '){
                list.push_back('%');
                list.push_back('2');
                list.push_back('0');
            } else{
                list.push_back(item);
            }
        }

        for (const auto &item : list)
            cout << item << endl;
        return string (list.begin(),list.end());
    }
};


int main() {
    Solution solution;
    solution.replaceSpace("he  ll");
    return 0;
}
