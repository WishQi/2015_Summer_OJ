//
//  main.cpp
//  7.22_E
//
//  Created by 李茂琦 on 7/25/15.
//  Copyright (c) 2015 李茂琦. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

long long max (long long x, long long y)
{
    long long max_elem = x;
    if (y > max_elem)
        max_elem = y;
    return max_elem;
}

int main(int argc, const char * argv[]) {
    
    string seq1, seq2;
    while (cin >> seq1 >> seq2) {
        long long length1 = seq1.length();
        long long length2 = seq2.length();
        vector<long long> row (length1 + 1, 0);
        vector< vector<long long> > state (length2 + 1, row);
        
        for (long long i = 0; i < length1; ++i) {
            for (long long j = 0; j < length2; ++j) {
                if (seq1[i] == seq2[j])
                    state[j + 1][i + 1] = state[j][i] + 1;
                else
                    state[j + 1][i + 1] = max (state[j][i + 1], state[j + 1][i]);
            }
        }
        cout << state[length2][length1] << endl;
    }
    return 0;
}
