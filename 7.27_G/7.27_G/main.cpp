//
//  main.cpp
//  7.27_G
//
//  Created by 李茂琦 on 7/29/15.
//  Copyright (c) 2015 李茂琦. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

int prime_factor[4] = {2, 3, 5, 7};
int prime_count[4];

int main(int argc, const char * argv[]) {
    
    long long num;
    
    while (cin >> num) {
        if (num == 0)
            break;
        
        memset(prime_count, 0, sizeof(prime_count));
        
        for (int i = 0; i < 4; ++i) {
            while (num % prime_factor[i] == 0) {
                ++prime_count[i];
                num = num / prime_factor[i];
            }
            ++prime_count[i];
        }
        
        int count = prime_count[0] * prime_count[1] * prime_count[2] * prime_count[3];
        
        cout << count << endl;
    }
    
    return 0;
}