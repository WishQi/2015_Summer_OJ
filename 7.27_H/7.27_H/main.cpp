//
//  main.cpp
//  7.27_H
//
//  Created by 李茂琦 on 7/29/15.
//  Copyright (c) 2015 李茂琦. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, int> prime;
vector<int> prime_count;
long long C[510][510];

const int mod = 1000000007;

void fillPrime(int n)
{
    for (int i = 2; i <= n; ++i) {
        if (n % i == 0)
            while (n % i == 0) {
                n = n / i;
                ++prime[i];
            }
    }
    if (n > 1)
        ++prime[n];
}

void initC ()
{
    for (int i = 0; i < 510; ++i) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++j)
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1] % mod;
    }
}

long long getC (long long n, long long m)
{
    return C[n + m - 1][n - 1];
}

long long getAns(int n)
{
    long long ans = 1;
    for (int i = 0; i < prime_count.size(); ++i) {
        ans = (ans * getC (n, prime_count[i])) % mod;
    }
    
    for (int i = 1; i < n; ++i) {
        long long temp = C[n][i];
        for (int j = 0; j < prime_count.size(); ++j)
            temp = (temp * getC(n - i, prime_count[j])) % mod;
        if (i & 1)
            ans = ((ans - temp) % mod + mod) % mod;
        else
            ans = (ans + temp) % mod;
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    
    initC();
    
    int n;
    while (cin >> n) {
        
        prime.clear();
        prime_count.clear();
        
        for (int i = 0; i < n; ++i) {
            int b;
            cin >> b;
            fillPrime(b);
        }
        
        for (auto itr = prime.begin(); itr != prime.end(); ++itr)
            prime_count.push_back(itr->second);
        
        cout << getAns(n) << endl;
        
    }
    return 0;
}