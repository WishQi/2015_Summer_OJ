//
//  main.cpp
//  7.24_C
//
//  Created by 李茂琦 on 7/26/15.
//  Copyright (c) 2015 李茂琦. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct each_snowflake
{
    int length[6];
    int total_length;
    int key;
    int get_key()
    {
        int toatal_length = length[0] + length[1] + length[2] + length[3] + length[4] + length[5];
        int key = toatal_length % 14997;
        return key;
    }
};

struct snowflakes
{
    vector<each_snowflake> index;
};

bool compare(each_snowflake& x, each_snowflake& y)
{
    if (x.length[0] == y.length[0] && x.length[1] == y.length[1] && x.length[2] == y.length[2]
        && x.length[3] == y.length[3] && x.length[4] == y.length[4] && x.length[5] == y.length[5])
        return true;
    else
        return false;
}

bool solve(snowflakes& list, each_snowflake& single)
{
    for (int i = 0; i < list.index.size(); ++i) {
        if ( compare(list.index[i], single) ) {
            return true;
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    
    int n;
    scanf("%d", &n);
    
    vector<each_snowflake> list;
    
    for (int i = 0; i < n; ++i) {
        each_snowflake x;
        for (int j = 0; j < 6; ++j) {
            int y;
            scanf("%d", &y);
            x.length[j] = y;
        }
        sort (x.length, x.length + 6);
        list.push_back(x);
    }
    
    snowflakes* key_list[14997];
    snowflakes hash[14997];
    
    for (int i = 0; i < 14997; ++i)
        key_list[i] = NULL;
    
    hash[list[0].get_key()].index.push_back(list[0]);
    key_list[list[0].get_key()] = &hash[list[0].get_key()];
    
    for (int i = 1; i < n; ++i) {
        int key = list[i].get_key();
        if (key_list[key] == NULL) {
            hash[key].index.push_back(list[i]);
            key_list[key] = & hash[key];
        }
        else {
            if ( solve(hash[key], list[i]) ) {
                cout << "Twin snowflakes found." << endl;
                return 0;
            }
            else
                hash[key].index.push_back(list[i]);
        }
    }
    
    cout << "No two snowflakes are alike." << endl;
    return 0;
}
















