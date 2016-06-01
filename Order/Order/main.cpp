//
//  main.cpp
//  Order
//
//  Created by 李茂琦 on 7/20/15.
//  Copyright (c) 2015 李茂琦. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    vector<int> vec = {23, 123, 11, 5, 9};
    int temp = 0;
    
/*选择排序
    for (int i = 0; i < 5; ++i) {
        for (int j = i + 1; j < 5; ++j) {
            if (vec[i] > vec[j]) {
                temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
            }
        }
    }
*/
    
/*冒泡排序
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (vec[j] > vec[j+1]) {
                temp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = temp;
            }
        }
    }
*/

/*插入排序
    for (int i = 1; i < 5; ++i) {
        int target = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > target) {
            vec[j+1] = vec[j];
            --j;
        }
        vec[j+1] = target;
    }
*/
    
    
    
    for (auto itr = vec.begin(); itr != vec.end(); ++itr)
        cout << *itr << " ";
    
    return 0;
}
