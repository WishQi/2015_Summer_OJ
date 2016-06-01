//
//  main.cpp
//  MergeSort
//
//  Created by 李茂琦 on 10/21/15.
//  Copyright © 2015 李茂琦. All rights reserved.
//

#include <iostream>
using namespace std;

double arr[10000];

void Merge(int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    double* arr1 = new double[n1];
    double* arr2 = new double[n2];
    
    for (int i = 0; i < n1; ++i)
        arr1[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        arr2[i] = arr[mid + i + 1];
    
    int k = left, i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            arr[k] = arr1[i];
            ++i;
        }
        else {
            arr[k] = arr2[j];
            ++j;
        }
        ++k;
    }
    while (i < n1) {
        arr[k] = arr1[i];
        ++i;
        ++k;
    }
    while (j < n2) {
        arr[k] = arr2[j];
        ++j;
        ++k;
    }
}

void MergeSort(int left, int right)
{
    if (left < right) {
        int mid = (left + right) / 2;
        MergeSort(left, mid);
        MergeSort(mid + 1, right);
        Merge(left, mid, right);
    }
}

int main(int argc, const char * argv[]) {
    for (int i = 0; i < 100; ++i) {
        arr[i] = rand() % 100;
    }
    
    MergeSort(0, 99);
    
    for (int i = 0; i < 100; ++i)
        cout << arr[i] << " ";
    
    return 0;
}
