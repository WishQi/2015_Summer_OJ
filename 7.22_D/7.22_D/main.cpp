//
//  main.cpp
//  7.22_D
//
//  Created by 李茂琦 on 7/24/15.
//  Copyright (c) 2015 李茂琦. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int max (int i, int j)
{
    int max_elem = i;
    if (j > max_elem)
        max_elem = j;
    return max_elem;
}

int main(int argc, const char * argv[]) {
    
    int state[1005][35][3];
    int whichTree[1005];
    
    int num, times, max_apples = -1;
    
    cin >> num >> times;
    
    for (int i = 1; i <= num; ++i)
        cin >> whichTree[i];
    
    for (int i = 1; i <= num; ++i) {
        for (int j = 0; j <= times; ++j) {
            for (int k = 1; k < 3; ++k) {
                if (i == 1) {
                    if (k == 1)
                        state[i][j][k] = (whichTree[i] == 1);
                    else if (j == times - 1)
                        state[i][j][k] = (whichTree[i] == 2);
                    else
                        state[i][j][k] = -1;
                }
                else {
                    if (state[i - 1][j][k] == -1 && state[i - 1][j + 1][3 - k] == -1)
                        state[i][j][k] = -1;
                    else {
                        if (state[i + 1][j][k] == -1)
                            state[i][j][k] = state[i - 1][j + 1][3 - k] + (whichTree[i] == k);
                        else if (state[i - 1][j + 1][3 - k] == -1)
                            state[i][j][k] = state[i - 1][j][k] + (whichTree[i] == k);
                        else
                            state[i][j][k] = max(state[i - 1][j][k], state[i - 1][j + 1][3 - k]) + (whichTree[i] == k);
                    }
                }
                max_apples = max (max_apples, state[i][j][k]);
            }
        }
    }
    
    cout << max_apples << endl;
    
    return 0;
}
