//
//  main.cpp
//  7.20_A
//
//  Created by 李茂琦 on 7/20/15.
//  Copyright (c) 2015 李茂琦. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int T;
    cin >> T;
    vector<double> Y;
    for (int i = 0; i < T; ++i) {
        double a;
        cin >> a;
        Y.push_back(a - 6);
    }
    
    double low = 0;
    double high = 100;
    
    double binary(double, double, double &);
    
    double max = 807020300;
    
    for (int i = 0; i < T; ++i) {
        if (Y[i] < 0 || Y[i] > max) {
            cout << "No solution!" << endl;
        } else {
            cout << setprecision(4) << fixed << binary(low, high, Y[i]) << endl;
        }
    }
    
    return 0;
}

double binary(double font, double end, double& key)
{
    double ans, result, precision;
    while (end > font) {
        ans = (font + end) / 2;
        result = 8 * ans * ans * ans * ans + 7 * ans * ans * ans + 2 * ans * ans + 3 * ans;
        precision = result - key;
        if (precision > 0.00001)
            end = ans;
        else if (precision < -0.00001)
            font = ans;
        else
            break;
        if (end == font)
            break;
    }
    
    return ans;
}









