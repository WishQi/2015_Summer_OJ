//
//  main.cpp
//  7.27_C
//
//  Created by 李茂琦 on 7/28/15.
//  Copyright (c) 2015 李茂琦. All rights reserved.
//

#include <iostream>
using namespace std;

int M[7];
int A[7];
int times;

int extended_euclid (int a, int b, int& x, int& y)
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

int euclid(int a, int b)
{
    if (b == 0)
        return a;
    int d = euclid(b, a % b);
    return d;
}

int calculate()
{
    int a, b, x, y, d, dm;
    int r, r1, r2;
    a = M[0];
    r1 = A[0];
    for (int i = 1; i < times; ++i) {
        b = M[i];
        r2 = A[i];
        r = r2 - r1;
        d = extended_euclid(a, b, x, y);
        if (r % d)
            return -1;
        dm = b / d;
        x = ((x * (r / d)) % dm + dm) % dm;     //why!!!!!!!!!!!!!!!
        r1 = a * x + r1;
        a = a * dm;
    }
    if (r1 == 0) {
        r1 = 1;
        for (int i = 0; i < times; ++i)
            r1 = r1 * M[i] / euclid(r1, M[i]);
    }
    return r1;
}

int main(int argc, const char * argv[]) {
    
    int case_num;
    cin >> case_num;
    
    for (int k = 0; k < case_num; ++k) {
        
        memset(M, 0, sizeof(M));
        memset(A, 0, sizeof(A));
        
        cin >> times;
        for (int i = 0; i < times; ++i)
            cin >> M[i];
        for (int i = 0; i < times; ++i)
            cin >> A[i];
        
        cout << "Case " << k + 1 << ": " << calculate() << endl;
    }
    
    return 0;
}
