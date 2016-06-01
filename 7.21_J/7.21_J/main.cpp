//
//  main.cpp
//  7.21_J
//
//  Created by 李茂琦 on 7/23/15.
//  Copyright (c) 2015 李茂琦. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dealWith(vector<int>& vec1, vector<int>& vec2, int& score)
{
    long long length = vec1.size() - 1;
    if (length >= 0) {
        if (vec1[0] > vec2[0]) {
            ++score;
            vec1.erase(vec1.begin());
            vec2.erase(vec2.begin());
            dealWith(vec1, vec2, score);
        } else if (vec1[0] < vec2[0]) {
            --score;
            vec1.erase(vec1.end() - 1);
            vec2.erase(vec2.begin());
            dealWith(vec1, vec2, score);
        } else {
            if (vec1[length] > vec2[length]) {
                vec1.erase(vec1.end() - 1);
                vec2.erase(vec2.end() - 1);
                ++score;
                dealWith(vec1, vec2, score);
            } else {
                if (vec1[length] < vec2[0])
                    --score;
                vec1.erase(vec1.end() - 1);
                vec2.erase(vec2.begin());
                dealWith(vec1, vec2, score);
            }
        }
    }
}


void full_fill (vector<int>& vec, int n)
{
    for (int i = 0; i < n; ++i) {
        int index;
        cin >> index;
        vec.push_back(index);
    }
}

int main() {
    
    int num;
    vector<int> result;
    
    while (cin >> num) {
        
        if (num == 0)
            break;
        
        vector<int> speed1, speed2;
        int score = 0;
        
        full_fill(speed1, num);
        full_fill(speed2, num);
        
        sort (speed1.begin(), speed1.end(), greater<int>());
        sort (speed2.begin(), speed2.end(), greater<int>());
        
        dealWith(speed1, speed2, score);
        
        result.push_back(score * 200);
    }
    
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }
    
    return 0;
}
