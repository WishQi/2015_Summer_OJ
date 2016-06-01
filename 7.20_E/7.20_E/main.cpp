//
//  main.cpp
//  7.20_E
//
//  Created by 李茂琦 on 7/20/15.
//  Copyright (c) 2015 李茂琦. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    
    int n, k;
    cin >> n >> k;
    
    vector< pair<long long, long long> > cow_list;
    vector< pair<long long, long long> > cow_list_copy;
    
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        pair<long long, long long> cow = make_pair(a, b);
        cow_list.push_back(cow);
        cow_list_copy.push_back(cow);
    }
    
    sort (cow_list.begin(), cow_list.end());
    reverse(cow_list.begin(), cow_list.end());
    
    long max = cow_list[0].second;
    for (int i = 0; i < k; ++i) {
        if (max < cow_list[i].second)
            max = cow_list[i].second;
    }
    
    for (int i = 0; i < n; ++i) {
        if (max == cow_list_copy[i].second) {
            cout << i + 1 << endl;
            break;
        }
    }
    
    return 0;
}
