//
//  main.cpp
//  7.20_3
//
//  Created by 李茂琦 on 7/20/15.
//  Copyright (c) 2015 李茂琦. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<vector<unsigned long long>> multiple(vector<vector<unsigned long long>> &matrix1, vector<vector<unsigned long long>> &matrix2)
{
    vector<vector<unsigned long long>> product = {{0, 0}, {0, 0}};
    product[0][0] = (matrix1[0][0] * matrix2[0][0] + matrix1[1][0] * matrix2[0][1]) % 7;
    product[1][0] = (matrix1[0][0] * matrix2[1][0] + matrix1[1][0] * matrix2[1][1]) % 7;
    product[0][1] = (matrix1[0][1] * matrix2[0][0] + matrix1[1][1] * matrix2[0][1]) % 7;
    product[1][1] = (matrix1[0][1] * matrix2[1][0] + matrix1[1][1] * matrix2[1][1]) % 7;
    return product;
}

int main(int argc, const char * argv[]) {
    int a, b, n;
    while (cin >> a >> b >> n) {
        if (a == 0 && b == 0 && n == 0) {
            break;
        }
        
        int index;
        if (n % 2 == 0)
            index = n/2 - 1;
        else
            index = n/2;
        
//        vector<vector<unsigned long long>> matrix = {{b, a}, {a*b, a*a+b}};
        unsigned long long A = b, B = a, C = a * b, D = a * a + b;
        
        vector<vector<unsigned long long>> ans = {{1, 0}, {0, 1}};
        vector<vector<unsigned long long>> temp = {{A, B}, {C, D}};
        
//        temp = multiple(temp, temp);
//        cout << temp[0][0] << " " << temp[0][1] << " " << temp[1][0] << " " << temp[1][1];
        
        while (index) {
            if (index & 1)
                ans = multiple(ans, temp);
            temp = multiple(temp, temp);
            index >>= 1;
        }
        int result;
        if (n % 2 == 0)
            result = ans[1][0] + ans[1][1];
        else
            result = ans[0][0] + ans[0][1];
        cout << result % 7 << endl;
    }
    return 0;
}
