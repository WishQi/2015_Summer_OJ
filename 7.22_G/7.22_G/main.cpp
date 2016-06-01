//
//  main.cpp
//  7.22_G
//
//  Created by 李茂琦 on 7/27/15.
//  Copyright (c) 2015 李茂琦. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

double max(double x, double y)
{
    return x > y ? x: y;
}

double state[10001];
int money[101];
double run[101];

int main() {
    
    int case_num;
    cin >> case_num;
    
    for (int k = 0; k < case_num; ++k) {
        
        memset(state, 0, sizeof(state));
        memset(money, 0, sizeof(money));
        memset(run, 0, sizeof(run));
        
        double risk;
        int bank_num;
        cin >> risk >> bank_num;
        
        int sum = 0;
        for (int i = 1; i <= bank_num; ++i) {
            cin >> money[i] >> run[i];
            sum += money[i];
            run[i] = 1 - run[i];
        }
        
        state[0] = 1.0;
        for (int i = 1; i <= bank_num; ++i) {
            for (int j = sum; j >= money[i]; --j) {
                state[j] = max (state[j - money[i]] * run[i], state[j]);
            }
        }
        
        for (int i = sum; i >= 0; --i) {
            if (state[i] > 1 - risk) {
                cout << i << endl;
                break;
            }
        }
        
    }
    
    return 0;
}
