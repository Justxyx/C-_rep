#include <iostream>
#include <iostream>
#include <string>
using namespace std;
#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

class Solution {
public:
    void reverseString(vector<char>& s) {
        int size = s.size() - 1;
        int i = 0;
        while ( size > i){
            swap(s[i],s[size]);
            ++ i;
            -- size;
        }
        for (const auto &item : s)
            cout << item << endl;
    }
};


int main() {
    Solution solution;
    char csa[10] = "hello";
    vector<char> v(csa,csa + 5);
    solution.reverseString(v);
    return 0;
}
