//
//  main.cpp
//  7.20_D
//
//  Created by 李茂琦 on 7/20/15.
//  Copyright (c) 2015 李茂琦. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int n;
    cin >> n;
    vector<int> produce;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        produce.push_back(a);
    }
    
    for (int i = 0; i < n; ++i) {
        int temp;
        for (int j = i + 1; j < n; ++j) {
            if (produce[i] > produce[j]) {
                temp = produce[i];
                produce[i] = produce[j];
                produce[j] = temp;
            }
        }
    }
    
    cout << produce[n/2] << endl;
    
    return 0;
}
