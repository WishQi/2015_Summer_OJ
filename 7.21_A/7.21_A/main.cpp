//
//  main.cpp
//  7.21_A
//
//  Created by 李茂琦 on 7/21/15.
//  Copyright (c) 2015 李茂琦. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int n;
    
    while (cin >> n) {
        map<string, int> color_list;
        string color;
        
        if (n == 0)
            break;
        
        for (int i = 0; i < n; ++i) {
            cin >> color;
            ++color_list[color];
        }
        
        pair<string, int> max = *color_list.begin();
        
        for (auto itr = color_list.begin(); itr != color_list.end(); ++itr) {
            if (itr->second > max.second)
                max = *itr;
        }
        
        cout << max.first << endl;
    }
    
    
    return 0;
}
