//
//  main.cpp
//  7.24_A
//
//  Created by 李茂琦 on 7/25/15.
//  Copyright (c) 2015 李茂琦. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


void min_heapify (vector<long long>& vec, int i)
{
    int left = i * 2;
    int right = i * 2 + 1;
    int min = i;
    if (left < vec.size() && vec[left] < vec[i])
        min = left;
    if (right < vec.size() && vec[right] < vec[min])
        min = right;
    if (min != i) {
        long long temp = vec[i];
        vec[i] = vec[min];
        vec[min] = temp;
        min_heapify(vec, min);
    }
}

void build_min_heap(vector<long long>& vec)
{
    for (int i = (vec.size() - 1) / 2; i >= 1; --i) {
        min_heapify(vec, i);
    }
}

int main(int argc, const char * argv[]) {
    
    int n;
    cin >> n;
    
    vector<long long> needed_wood(1, 0);
    int length = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        length += x;
        needed_wood.push_back(x);
    }
    
    build_min_heap(needed_wood);
    
    long long sum = 0;
    
    if (needed_wood.size() > 3) {
        while (needed_wood.size() > 3) {
            if (needed_wood[2] <= needed_wood[3]) {
                sum += needed_wood[1] + needed_wood[2];
                needed_wood[2] = needed_wood[1] + needed_wood[2];
            }
            else {
                sum += needed_wood[1] + needed_wood[3];
                needed_wood[3] = needed_wood[1] + needed_wood[3];
            }
            needed_wood[1] = needed_wood[needed_wood.size() - 1];
            needed_wood.pop_back();
            build_min_heap(needed_wood);
        }
        sum += length;
    }
    else if (needed_wood.size() == 3)
        sum = length;
    
    cout << sum << endl;
    
    return 0;
}
