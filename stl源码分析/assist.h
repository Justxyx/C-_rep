//
// Created by 肖应雄 on 2021/12/22.
//

#ifndef STL_ASSIST_H
#define STL_ASSIST_H

#include <iostream>
using namespace std;

long get_a_target(){
    long target = 0;
    cout << " target  (0 ~ " << RAND_MAX <<  ")" << endl;
    cin >> target ;
    return target;
}

string get_a_target_string(){
    int target = 0;
    char buf[10];
    cout << " target  (0 ~ " << RAND_MAX <<  ")" << endl;
    cin >> target;
    snprintf(buf,10,"%d",target);
    return string(buf);
}

int compare_longs(const void *a,const void *b){
    return (*(long*)a - *(long*)b);
}

int compare_strings(const void *a,const void *b){
    if ( *(string*)a > *(string*)b){
        return 1;
    } else if (*(string*)a < *(string*)b)
    {
        return -1;
    } else
    {
        return 0;
    }
}


#endif //STL_ASSIST_H
