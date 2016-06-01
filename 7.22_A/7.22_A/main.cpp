//
//  main.cpp
//  7.22_A
//
//  Created by 李茂琦 on 7/22/15.
//  Copyright (c) 2015 李茂琦. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int case_number;
    cin >> case_number;
    vector< pair<int, int> > result;
    vector<int> result2;
    
    for (int i = 0; i < case_number; ++i) {
        
        int num;
        cin >> num;
        
        vector<int> sum_list = {0};
        int sum = 0;
        for (int i = 0; i < num; ++i) {
            int n;
            cin >> n;
            sum += n;
            sum_list.push_back(sum);
        }
        
        int max_sub_sum = sum_list[1];
        int min_sum = 0;
        int from = 1;
        int to = 1;
        int min_index = 0;
        
        for (int i = 1; i < num + 1; ++i) {
            if (sum_list[i] - min_sum > max_sub_sum) {
                max_sub_sum = sum_list[i] - min_sum;
                to = i;
                from = min_index + 1;
            }
            if (min_sum > sum_list[i]) {
                min_sum = sum_list[i];
                min_index = i;
            }
        }
        
        
        pair<int, int> area = make_pair(from, to);
        result.push_back(area);
        result2.push_back(max_sub_sum);
    }
    
    for (int i = 0; i < case_number; ++i) {
        cout << "Case " << i + 1 << ":" << endl;
        cout << result2[i] << " "<< result[i].first << " " << result[i].second << endl;
        if (i != case_number - 1)
            cout << "\n";
    }
    
    return 0;
}
