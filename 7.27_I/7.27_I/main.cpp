//
//  main.cpp
//  7.27_I
//
//  Created by 李茂琦 on 7/29/15.
//  Copyright (c) 2015 李茂琦. All rights reserved.
//

#include <iostream>
using namespace std;

int arr[100001][100001];

int euclid(int a, int b)
{
    if (b == 0)
        return a;
    int d = euclid(b, a % b);
    return d;
}

int main(int argc, const char * argv[]) {
    
    int case_num;
    cin >> case_num;
    
    for (int m = 0; m < case_num; ++m) {
        int a, b, c, d, k, pairs = 0;
        cin >> a >> b >> c >> d >> k;
        
        memset(arr, 0, sizeof(arr));
        
        for (int i = a; i <= b; ++i) {
            for (int j = c; j <= d; ++j) {
                if (arr[i][j] == 0 && arr[j][i] == 0) {
                    arr[i][j] = 1;
                    if (euclid(i, j) == k)
                        ++pairs;
                }
            }
        }
        
        cout << "Case " << m + 1 << ": " << pairs << endl;
    }
    
    return 0;
}
