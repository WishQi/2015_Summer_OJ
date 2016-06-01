//
//  main.cpp
//  7.22_H
//
//  Created by 李茂琦 on 12/5/15.
//  Copyright © 2015 李茂琦. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int max(int x, int y)
{
    return x > y ? x : y;
}

int main(int argc, const char * argv[]) {
    
    int N, M;
    scanf("%d %d", &N, &M);
    
    int w[3500], v[3500], c[13000];
    
    memset(c, 0, sizeof(c));
    
    for (int i = 1; i <= N; ++i) {
        scanf("%d %d", &w[i], &v[i]);
    }
    
    for (int i = 1; i <= N; ++i) {
        for (int j = M; j >= w[i]; --j) {
            c[j] = max(c[j], c[j - w[i]] + v[i]);
        }
    }
    
    printf("%d\n", c[M]);
    
    return 0;
}
