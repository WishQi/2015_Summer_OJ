//
//  main.cpp
//  7.28_A
//
//  Created by 李茂琦 on 7/30/15.
//  Copyright (c) 2015 李茂琦. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int n;
    cin >> n;
    
    int min1, min2, min3, max1, max2, max3;
    cin >> min1 >> max1 >> min2 >> max2 >> min3 >> max3;
    
    int first = max1;
    int second = max2;
    int third = max3;
    
    while (first + second + third > n) {
        if (third > min3)
            --third;
        else {
            if (second > min2)
                --second;
            else
                --first;
        }
    }
    
    cout << first << " " << second << " " << third << endl;
    
    return 0;
}
