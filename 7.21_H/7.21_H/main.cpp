//
//  main.cpp
//  7.21_H
//
//  Created by 李茂琦 on 7/23/15.
//  Copyright (c) 2015 李茂琦. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <utility>
#include <stdio.h>
using namespace std;

int main() {
    
    vector<int> result;
    vector<int> except;
    
    for (int k = 0; ;++k) {
        int num = 0, radius = 0;
        cin >> num >> radius;
        
        if (num == 0 && radius == 0)
            break;
        
        vector< pair<double, double> > area;
        int radar = 1;
    
        for (int i = 0; i < num; ++i) {
            int x, y;
            cin >> x >> y;
            double max = 0, min = 0;
            double judge = radius * radius - y * y;
            if (judge < 0 || radius <= 0) {
                except.push_back(k);
            } else {
                max = x + sqrt(judge);
                min = x - sqrt(judge);
            }
            pair<double, double> elem = make_pair(min, max);
            area.push_back(elem);
        }
    
        sort(area.begin(), area.end());
        
        int start = 0;
        for (int i = start + 1; i < num; ++i) {
            if (area[i].first <= area[start].second) {
                if (area[i].second > area[start].second) {
                    area[i].second = area[start].second;
                }
            } else {
                ++radar;
            }
            start = i;
        }
        
        result.push_back(radar);
        
        char next = getchar();
    }
    
    for (int i = 0; i < result.size(); ++i) {
        vector<int>::iterator itr = find(except.begin(), except.end(), i);
        if (itr == except.end())
            cout << "Case " << i + 1 << ": " << result[i] << endl;
        else
            cout << "Case " << i + 1 << ": " << "-1" << endl;
    }
    
    return 0;
}



















