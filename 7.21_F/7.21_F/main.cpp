//
//  main.cpp
//  7.21_F
//
//  Created by 李茂琦 on 7/21/15.
//  Copyright (c) 2015 李茂琦. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
using namespace std;

void quick_sort(vector<vector<int>>& vec, int left, int right)
{
    if (left < right) {
        int low = left;
        int high = right;
        int key = vec[low][0];
        vector<int> key_match = vec[low];
        while (low < high) {
            while (low < high && vec[high][0] > key)
                --high;
            if (low < high)
                vec[low++] = vec[high];
            while (low < high && vec[low][0] <= key)
                ++low;
            if (low < high)
                vec[high--] = vec[low];
        }
        vec[low] = key_match;
        quick_sort(vec, left, low - 1);
        quick_sort(vec, low + 1, right);
    }
}

int main(int argc, const char * argv[]) {
    int case_num;
    cin >> case_num;
    
    for (int _case = 0; _case < case_num; ++_case) {
        int n;
        cin >> n;
        
        vector<vector<int>> moveTo;
        vector<int> room;
        
        for (int i = 0; i < n; ++i) {
            int room1, room2;
            cin >> room1 >> room2;
            if (room1 > room2) {
                room.push_back(room2);
                room.push_back(room1);
                moveTo.push_back(room);
            } else {
                room.push_back(room1);
                room.push_back(room2);
                moveTo.push_back(room);
            }
            room.clear();
        }
        
        quick_sort(moveTo, 0, n - 1);
        
        int time = 0;
        
        for (int i = 0; i < n; ++i) {
            int k = i;
            if (moveTo[k][0] != 0) {
                for (int j = k + 1; j < n; ++j) {
                    if (moveTo[j][0] != 0) {
                        int low = (moveTo[k][1] + 1) / 2;
                        int high = (moveTo[j][0] + 1) / 2;
                        if (low < high) {
                            moveTo[k][0] = 0;
                            moveTo[j][0] = 0;
                            k = j;
                        }
                    }
                }
                ++time;
            }
        }
        cout << time * 10 << endl;
    }
    
    return 0;
}
