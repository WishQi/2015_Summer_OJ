//
//  main.cpp
//  7.21_B
//
//  Created by 李茂琦 on 7/21/15.
//  Copyright (c) 2015 李茂琦. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int n;
    vector<string> str_list;
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        str_list.push_back(str);
    }
    
    for (auto itr = str_list.begin(); itr != str_list.end(); ++itr) {
        vector<char> letter_list;
        vector<int> index_list;
        int index = 1;
        char letter = (*itr)[0];
        letter_list.push_back(letter);
        for (int i = 1; i < itr->size(); ++i) {
            if (letter != (*itr)[i]) {
                index_list.push_back(index);
                index = 1;
//                letter_list.push_back(letter);
                letter = (*itr)[i];
                letter_list.push_back(letter);
            } else
                ++index;
            if (i == itr->size() - 1)
                index_list.push_back(index);
        }
        for (int i = 0; i < letter_list.size(); ++i) {
            if (index_list[i] != 1) {
                cout << index_list[i];
            }
            cout << letter_list[i];
        }
        cout << "\n";
    }
    
    return 0;
}
