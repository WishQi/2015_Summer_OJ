//
//  main.cpp
//  7.20_1
//
//  Created by 李茂琦 on 7/20/15.
//  Copyright (c) 2015 李茂琦. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int a, b;
    while(cin >> a >> b) {
        unsigned long long ans = 1, temp = a;
        while (b) {
            if (b & 1)
                ans = ans * temp % 10;
            temp = temp * temp % 10;
            b >>= 1;
        }
        cout << ans << endl;
    }
    return 0;
}