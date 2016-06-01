//
//  main.cpp
//  7.27_F
//
//  Created by 李茂琦 on 7/28/15.
//  Copyright (c) 2015 李茂琦. All rights reserved.
//

#include <iostream>
using namespace std;

long long phi (long long n)
{
    long long count = n;
    for (long long i = 2; i <= n; ++i) {
        if (n % i == 0) {
            count = count * (i - 1) / i;
            while (n % i == 0)
                n = n / i;
        }
    }
    if (n > 1)
        count = count * (n - 1) / n;
    return count;
}

long long quick_mod(long long a, long long b, long long m)
{
    long long ans = 1, temp = a;
    while (b) {
        if (b & 1) {
            ans = ans * temp;
            if (ans >= m)
                ans = ans % m + m;
        }
        temp = temp * temp;
        if (temp >= m)
            temp = temp % m + m;
        b >>= 1;
    }
    return ans;
}


long long getAnswer(long long n, long long m)
{
    if (n < 10)
        return n;
    long long p = getAnswer(n / 10, phi(m));
    return quick_mod(n % 10, p, m);
}

int main(int argc, const char * argv[]) {
    
    int case_num;
    cin >> case_num;
    
    for (int k = 0; k < case_num; ++k) {
        long long n, m;
        cin >> n >> m;
        
        long long ans = getAnswer(n, m);
        ans = ans % m;
        cout << ans << endl;
    }
    
    return 0;
}