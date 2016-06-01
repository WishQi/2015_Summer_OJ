//
//  main.cpp
//  7.27_B
//
//  Created by 李茂琦 on 7/27/15.
//  Copyright (c) 2015 李茂琦. All rights reserved.
//

#include <iostream>
using namespace std;

int extended_euclid (int a, int b, int& x, int& y)
{
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    } else {
        int d = extended_euclid(b, a % b, x, y);
        int temp = x;
        x = y;
        y = temp - a / b * y;
        return d;
    }
}

int main(int argc, const char * argv[]) {
    
    int case_num;
    cin >> case_num;
    
    for (int i = 0; i < case_num; ++i) {
        int a, b = 9973, x = 0, y = 0, n;
        cin >> n >> a;
        extended_euclid(a, b, x, y);
        x = x * n;
//        x = x % 9973;
        x = (x % 9973 + 9973) % 9973;      //why must x be nonegetive????
        cout << x << endl;
    }
    return 0;
}
