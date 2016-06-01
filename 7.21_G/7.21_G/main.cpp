//
//  main.cpp
//  7.21_G
//
//  Created by 李茂琦 on 7/21/15.
//  Copyright (c) 2015 李茂琦. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


void quick_sort(vector<unsigned long long>& vec, int left, int right)
{
    if (left < right) {
        int low = left;
        int high = right;
        int key = vec[low];
        while (low < high) {
            while (low < high && vec[high] <= key)
                --high;
            if (low < high)
                vec[low++] = vec[high];
            while (low < high && vec[low] > key)
                ++low;
            if (low < high)
                vec[high--] = vec[low];
        }
        vec[low] = key;
        quick_sort(vec, left, low - 1);
        quick_sort(vec, low + 1, right);
    }
}

int main(int argc, const char * argv[]) {
    
    unsigned long long crack_length, block_num;
    while( cin >> crack_length >> block_num ) {
    
        vector<unsigned long long> blocks_list;
        for (int i = 0; i < block_num; ++i) {
            unsigned long long length;
            cin >> length;
            blocks_list.push_back(length);
        }
    
        quick_sort(blocks_list, 0, block_num - 1);
    
        unsigned long long sum = 0;
        int min = 0;
        while (min < block_num) {
            sum += blocks_list[min];
            if (sum >= crack_length)
                break;
            ++min;
        }
        if (min == block_num)
            cout << "impossible" << endl;
        else
            cout << min + 1 << endl;
    }
    
    return 0;
}
