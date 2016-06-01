//
//  main.cpp
//  7.21_I
//
//  Created by 李茂琦 on 7/21/15.
//  Copyright (c) 2015 李茂琦. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void quick_sort(vector< vector<long long> >& vec, int left, int right)
{
    if (left < right) {
        int low = left;
        int high = right;
        vector<long long> key = vec[low];
        while (low < high) {
            while (low < high && vec[high][0] > key[0])
                --high;
            if (low < high)
                vec[low++] = vec[high];
            while (low < high && vec[low][0] <= key[0])
                ++low;
            if (low < high)
                vec[high--] = vec[low];
        }
        vec[low] = key;
        quick_sort(vec, left, low - 1);
        quick_sort(vec, low + 1, right);
    }
}

void full_fill(vector< vector<long long> >& vec, int n)
{
    for (int i = 0; i < n; ++i) {
        vector<long long> index;
        long long data;
        cin >> data;
        index.push_back(data);
        index.push_back(i + 1);
        vec.push_back(index);
    }
}

int main() {
    
    int n;
    unsigned long long t;
    cin >> n >> t;
    
    vector< vector<long long> > weight, distance, price;
    
    full_fill(weight, n);
    full_fill(distance, n);
    full_fill(price, n);
    
    vector< vector<long long> > cost_list;
    for (int i = 0; i < n; ++i) {
        vector<long long> index;
        long long cost = price[i][0] - t * distance[i][0];
        index.push_back(cost);
        index.push_back(i + 1);
        cost_list.push_back(index);
    }
    
    quick_sort(cost_list, 0, n - 1);
    quick_sort(weight, 0, n - 1);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (cost_list[j][1] == i + 1) {
                if (i == n - 1)
                    cout << weight[j][1] << endl;
                else
                    cout << weight[j][1] << " ";
            }
        }
    }
    
    return 0;
}