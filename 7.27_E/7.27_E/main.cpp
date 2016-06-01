//
//  main.cpp
//  7.27_E
//
//  Created by 李茂琦 on 7/28/15.
//  Copyright (c) 2015 李茂琦. All rights reserved.
//

#include <iostream>
using namespace std;

int phi[3000000];
int prime[3000000];
bool isPrime[3000000];

void make_phi ()
{
    int k = 0;
    for (int i = 2; i < 3000000; ++i) {
        if ( !isPrime[i] ) {
            phi[i] = i - 1;
            prime[k++] = i;
        }
        for (int j = 0; j < k && i * prime[j] < 3000000; ++j) {
            
            isPrime[i * prime[j]] = true;
            
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
            }
            else
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
        }
    }
}

int main(int argc, const char * argv[]) {
    
    make_phi();
    int a, b;
    while (cin >> a >> b) {
        long long sum = 0;
        for (int i = a; i <= b; ++i)
            sum += phi[i];
        cout << sum << endl;
    }
    
    return 0;
}
