//
//  main.cpp
//  7.21_C
//
//  Created by 李茂琦 on 7/21/15.
//  Copyright (c) 2015 李茂琦. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int visited[11][11];
vector<string> maze;

int row, column, steps;

bool go_maze(int posX, int posY)
{
    visited[posX][posY] = ++steps;

    int nextX, nextY;
    if ( maze[posX][posY] == 'N' ) {
        nextX = posX - 1;
        nextY = posY;
    }
    if ( maze[posX][posY] == 'S' ) {
        nextX = posX + 1;
        nextY = posY;
    }
    if ( maze[posX][posY] == 'W' ) {
        nextY = posY - 1;
        nextX = posX;
    }
    if ( maze[posX][posY] == 'E' ) {
        nextY = posY + 1;
        nextX = posX;
    }
    
    if ( nextX >= row || nextX < 0 || nextY >= column || nextY < 0 ) {
        cout << steps << " step(s) to exit" << endl;
        return true;
    }
    
    if ( visited[nextX][nextY] != 0 ) {
        cout << visited[nextX][nextY] - 1 << " step(s) before a loop of " << (visited[posX][posY] - visited[nextX][nextY] + 1) << " step(s)" << endl;
        return true;
    }
    
    go_maze(nextX, nextY);
    
    return true;
}

int main(int argc, const char * argv[]) {
    int start_pos;
    while (cin >> row >> column >> start_pos) {
        if (row == 0 || column == 0 || start_pos == 0)
            break;
        for (int i = 0; i < row; ++i) {
            string str;
            cin >> str;
            maze.push_back(str);
        }
        go_maze(0, start_pos - 1);
        maze.clear();
        for (int i = 0; i < 11; ++i) {
            for (int j = 0; j < 11; ++j)
                visited[i][j] = 0;
        }
        steps = 0;
    }
    return 0;
}
