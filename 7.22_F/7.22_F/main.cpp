//
//  main.cpp
//  7.22_F
//
//  Created by 李茂琦 on 7/25/15.
//  Copyright (c) 2015 李茂琦. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


int max (int x, int y)
{
    int max_elem = x;
    if (max_elem < y)
        max_elem = y;
    return max_elem;
}

int main(int argc, const char * argv[]) {
    
    int n;
    while (cin >> n) {
        
        if (n == 0)
            break;
        
        vector<int> chess;
        for (int i = 0; i < n; ++i) {
            int chessman;
            cin >> chessman;
            chess.push_back(chessman);
        }
        
        int state[1001] = {chess[0]};
        int max_sum = state[0];
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (state[i] == 0)
                    state[i] = chess[i];
                int now = state[i];
                if (chess[j] < chess[i])
                    state[i] = state[j] + chess[i];
                state[i] = max (now, state[i]);
            }
            max_sum = max (max_sum, state[i]);
        }
        cout << max_sum << endl;
    }
    
    return 0;
}