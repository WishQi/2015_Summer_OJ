//
//  main.cpp
//  7.22_B
//
//  Created by 李茂琦 on 7/22/15.
//  Copyright (c) 2015 李茂琦. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > arr;
int n;
int memory[101][101];

int dynamic(int x, int y)
{
    int sub_max = 0;
    if (x < n && y < n) {
        int left, right;
        if (memory[x + 1][y] != -1)
            left = memory[x + 1][y];
        else
            left = dynamic(x + 1, y);
        if (memory[x + 1][y + 1] != -1)
            right = memory[x + 1][y + 1];
        else
            right = dynamic(x + 1, y + 1);
        sub_max = arr[x][y] + max(left, right);
    }
    
    memory[x][y] = sub_max;
    return sub_max;
}

int max(int left, int right)
{
    int max_leaf = 0;
    if (left > right)
        max_leaf = left;
    else
        max_leaf = right;
    return max_leaf;
}

int main() {
    
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            memory[i][j] = -1;
    }
    
    for (int i = 0; i < n; ++i) {
        vector<int> row;
        for (int j = 0; j < i + 1; ++j) {
            int num;
            cin >> num;
            row.push_back(num);
        }
        arr.push_back(row);
    }
    
    int ans = dynamic(0, 0);
    cout << ans;
    return 0;
}
