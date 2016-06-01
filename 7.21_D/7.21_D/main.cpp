//
//  main.cpp
//  7.21_D
//
//  Created by 李茂琦 on 7/22/15.
//  Copyright (c) 2015 李茂琦. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


string simplify(string& num)
{
    string rightStr;
    
    if (num[0] == '-') {
        auto ptr = num.begin();
        for (unsigned long long int i = 0; i < num.length(); ++i, ++ptr) {
            if (num[i] != '-')
                break;
        }
        num = string(ptr, num.end());
    }
    
    string::iterator itr1 = num.begin();
    string::iterator itr2 = num.end();
    long long int length = num.length();
    
    
    if (num[0] == '0') {
        for (unsigned long long int i = 0; i < length; ++i, ++itr1) {
            if (num[i] != '0')
                break;
        }
    }
    
    auto itr = find(num.begin(), num.end(), '.');
    
    if (itr != num.end()) {
        if (num[length - 1] == '0' || num[length-1] == '.') {
        
            for (long long int i = length - 1; i >= 0; --i, --itr2) {
                if (num[i] == '.') {
                    --itr2;
                }
                if (num[i] != '0')
                    break;
            }
        }
    }
    
    rightStr = string(itr1, itr2);
    
    return rightStr;
}

int main(int argc, const char * argv[]) {
    
    string num1, num2;
    while (cin >> num1 >> num2) {
        
        string right_num1, right_num2;
        
        if ((num1[0] == '-' && num2[0] != '-') || (num1[0] != '-' && num2[0] == '-')) {
            cout << "NO" << endl;
            continue;
        }
        
        right_num1 = simplify(num1);
        right_num2 = simplify(num2);
        
        if (right_num1 == right_num2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    return 0;
}
