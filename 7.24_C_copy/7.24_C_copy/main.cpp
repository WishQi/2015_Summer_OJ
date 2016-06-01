//
//  main.cpp
//  7.24_C_copy
//
//  Created by 李茂琦 on 7/26/15.
//  Copyright (c) 2015 李茂琦. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int n;
    cin >> n;
    vector< pair< int, vector<int> > > snowflakes;
    
    for (int i = 0; i < n; ++i) {
        pair<int, vector<int> > each;
        vector<int> vec;
        int sum = 0;
        for (int j = 0; j < 6; ++j) {
            int x;
            cin >> x;
            sum += x;
            vec.push_back(x);
        }
        sort (vec.begin(), vec.end());
        each.first = sum;
        each.second = vec;
        snowflakes.push_back(each);
    }
    
    sort (snowflakes.begin(), snowflakes.end());
    
    for (int i = 0; i < n - 1; ++i) {
        int j = i + 1;
        if (snowflakes[i].second[0] == snowflakes[j].second[0] && snowflakes[i].second[1] == snowflakes[j].second[1]
            && snowflakes[i].second[2] == snowflakes[j].second[2] && snowflakes[i].second[3] == snowflakes[j].second[3]
            && snowflakes[i].second[4] == snowflakes[j].second[4] && snowflakes[i].second[5] == snowflakes[j].second[5]) {
            cout << "Twin snowflakes found." << endl;
            return 0;
        }
    }
    
    cout << "No two snowflakes are alike." << endl;
    return 0;
}
