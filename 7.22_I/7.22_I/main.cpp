//
//  main.cpp
//  7.22_I
//
//  Created by 李茂琦 on 12/5/15.
//  Copyright © 2015 李茂琦. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define INF 0x7fffff
int c[10010];

int minMoney(int x, int y)
{
    return x < y ? x : y;
}

int main(int argc, const char * argv[]) {
    
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int E, F, N, M;
        scanf("%d%d", &E, &F);
        scanf("%d", &N);
        M = F - E;
        
        for (int i = 1; i <= M; ++i)
            c[i] =INF;
        c[0] = 0;
        
        while (N--) {
            int p, w;
            scanf("%d%d", &p, &w);
            for (int i = w; i <= M; ++i)
                c[i] = minMoney(c[i], c[i - w] + p);
        }
        
        if (c[M] == INF)
            printf("This is impossible.\n");
        else
            printf("The minimum amount of money in the piggy-bank is %d.\n", c[M]);
        
    }
    
    return 0;
}