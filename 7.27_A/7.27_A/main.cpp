//
//  main.cpp
//  7.27_A
//
//  Created by 李茂琦 on 7/27/15.
//  Copyright (c) 2015 李茂琦. All rights reserved.
//

#include <iostream>
using namespace std;

int extended_euclid(int a, int b, int& x, int& y)
{
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    else {
        int d = extended_euclid(b, a % b, x, y);
        int temp = x;
        x = y;
        y = temp - a / b * y;
        return d;
    }
}


int main(int argc, const char * argv[]) {
    
    int a, b, x = 0, y = 0;
    
    while (cin >> a >> b) {
        int d = extended_euclid(a, b, x, y);
        if (d == 1) {
            while (x < 0) {
                x += b;
                y -= a;
            }
            cout << x << " " << y << endl;
        }
        else
            cout << "sorry" << endl;
    }
    
    
    
    return 0;
}
