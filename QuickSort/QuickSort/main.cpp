//
//  main.cpp
//  QuickSort
//
//  Created by 李茂琦 on 10/21/15.
//  Copyright © 2015 李茂琦. All rights reserved.
//

#include <iostream>
using namespace std;


double arr[100000];

void swap(double& x, double& y)
{
    double temp = x;
    x = y;
    y = temp;
}

int Partition(int left, int right)
{
    double key = arr[right];
    int i = left - 1;
    for (int j = left; j < right; ++j) {
        if (arr[j] < key) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

void QuickSort(int left, int right)
{
    if (left < right) {
        int mid = Partition(left, right);
        QuickSort(left, mid - 1);
        QuickSort(mid + 1, right);
    }
}

int main(int argc, const char * argv[]) {
    
    for (int i = 0; i < 100; ++i) {
        arr[i] = rand() % 100;
    }
    
    QuickSort(0, 99);
    
    for (int i = 0; i < 100; ++i)
        cout << arr[i] << " ";
    
    return 0;
}
