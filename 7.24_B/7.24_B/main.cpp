//
//  main.cpp
//  7.24_B
//
//  Created by 李茂琦 on 7/26/15.
//  Copyright (c) 2015 李茂琦. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int cows;
    cin >> cows;
    
    priority_queue<int> products;
    for (int i = 0; i < cows; ++i) {
        int n;
        cin >> n;
        products.push(n);
    }
    
    int start_size = products.size();
    while (products.size() > (start_size + 1) / 2)
        products.pop();
    
    cout << products.top() << endl;
    return 0;
}
