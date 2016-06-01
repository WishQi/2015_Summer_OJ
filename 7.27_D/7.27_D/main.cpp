//
//  main.cpp
//  7.27_D
//
//  Created by 李茂琦 on 7/28/15.
//  Copyright (c) 2015 李茂琦. All rights reserved.
//

#include <iostream>
using namespace std;

int arr[32768];

int main(int argc, const char * argv[]) {
    
    int case_num;
    cin >> case_num;
    
    for (int i = 0; i < case_num; ++i) {
        int num;
        cin >> num;
        
        memset(arr, 0, sizeof(arr));
        
        for (int i = 2; i < num; ++i) {
            if (num % i == 0)
                for (int j = i; j < num; j += i)
                    arr[j] = 1;
        }
            
        int count = 0;
        for (int i = 1; i < num; ++i) {
            if (arr[i] == 0)
                ++count;
        }
        cout << count << endl;
    }
    
    return 0;
}
