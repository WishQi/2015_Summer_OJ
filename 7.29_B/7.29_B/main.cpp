//
//  main.cpp
//  7.29_B
//
//  Created by 李茂琦 on 11/22/15.
//  Copyright © 2015 李茂琦. All rights reserved.
//

#include <iostream>
using namespace std;

int pre[1050];

int find(int x)
{
    int root = x;
    while (pre[root] != root) {
        root = pre[root];
    }
    
    while (pre[x] != root) {
        int j = pre[x];
        pre[x] = root;
        x = j;
    }
    
    return root;
}

void join(int a, int b)
{
    int ra = find(a);
    int rb = find(b);
    if (ra != rb)
        pre[ra] = rb;
}

int main(int argc, const char * argv[]) {
    
    int case_num;
    scanf("%d", &case_num);
    
    for (int i = 0; i < case_num; ++i) {
        int N, M;
        scanf("%d %d", &N, &M);
        
        for (int k = 1; k <= N; ++k) {
            pre[k] = k;
        }
        
        for (int j = 0; j < M; ++j) {
            int a, b;
            scanf("%d %d", &a, &b);
            join(a, b);
        }
        
        int area = 0;
        for (int p = 1; p <= N; ++p) {
            if (pre[p] == p)
                ++area;
        }
        printf("%d\n", area);
        
        getchar();
    }
    return 0;
}
