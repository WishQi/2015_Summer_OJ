//
//  main.cpp
//  7.21_E
//
//  Created by 李茂琦 on 7/21/15.
//  Copyright (c) 2015 李茂琦. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    vector<int> index_list;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        index_list.push_back(num);
    }
    
    int total_list[1000] = {0};
    for (int i = 1; i <= 1000; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (i % j == 0) {
                ++(total_list[i-1]);
            }
        }
    }
    
    for (int i = 0; i < n; ++i) {
        int j = 0;
        for (; j < 1000; ++j) {
            if (index_list[i] == total_list[j]) {
                cout << j + 1 << endl;
                break;
            }
        }
        if (j == 1000)
            cout << -1 << endl;
    }
    
    
    return 0;
}