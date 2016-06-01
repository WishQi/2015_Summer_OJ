//
//  main.cpp
//  7.22_C
//
//  Created by 李茂琦 on 7/24/15.
//  Copyright (c) 2015 李茂琦. All rights reserved.
//

#include <iostream>
using namespace std;

int row, column;

int height[101][101];
int max_length[101][101];

int up_down[] = {-1, 0, 1, 0};
int left_right[] = {0, -1, 0, 1};

int max (int route[4])
{
    int max_elem = route[0];
    for (int i = 1; i < 4; ++i) {
        if (route[i] > max_elem)
            max_elem = route[i];
    }
    return max_elem;
}

int go_max_route (int x, int y)
{
    int route[4];
    for (int i = 0; i < 4; ++i) {
        int nextX = x + up_down[i];
        int nextY = y + left_right[i];
        if (nextX >= 0 && nextX < row && nextY >= 0 && nextY < column) {
            if (height[nextX][nextY] < height[x][y]) {
                if (max_length[nextX][nextY] != 0)
                    route[i] = max_length[nextX][nextY] + 1;
                else
                    route[i] = go_max_route(nextX, nextY) + 1;
            } else
                route[i] = 1;
        } else
            route[i] = 1;
    }
    max_length[x][y] = max(route);
    return max_length[x][y];
}

int main(int argc, const char * argv[]) {
    cin >> row >> column;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            cin >> height[i][j];
        }
    }
    
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            if (max_length[i][j] == 0)
                go_max_route(i, j);
        }
    }
    
    int find_it = max_length[0][0];
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            if (find_it < max_length[i][j])
                find_it = max_length[i][j];
        }
    }
    
    cout << find_it << endl;
    
    return 0;
}
