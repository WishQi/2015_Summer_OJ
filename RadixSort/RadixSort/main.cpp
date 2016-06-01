//
//  main.cpp
//  RadixSort
//
//  Created by 李茂琦 on 10/21/15.
//  Copyright © 2015 李茂琦. All rights reserved.
//

#include <iostream>
using namespace std;

int arr[10000];

int GetNumInPos(int num,int pos)
{
    int temp = 1;
    for (int i = 0; i < pos - 1; i++)
        temp *= 10;
    
    return (num / temp) % 10;
}

/********************************************************
 *函数名称：RadixSort
 *参数说明：pDataArray 无序数组；
 *          iDataNum为无序数据个数
 *说明：    基数排序
 *********************************************************/
#define RADIX_10 10    //整形排序
#define KEYNUM_31 10     //关键字个数，这里为整形位数
void RadixSort(int iDataNum)
{
    int *radixArrays[RADIX_10];    //分别为0~9的序列空间
    for (int i = 0; i < 10; i++)
    {
        radixArrays[i] = (int *)malloc(sizeof(int) * (iDataNum + 1));
        radixArrays[i][0] = 0;    //index为0处记录这组数据的个数
    }
    
    for (int pos = 1; pos <= KEYNUM_31; pos++)    //从个位开始到31位
    {
        for (int i = 0; i < iDataNum; i++)    //分配过程
        {
            int num = GetNumInPos(arr[i], pos);
            int index = ++radixArrays[num][0];
            radixArrays[num][index] = arr[i];
        }
        
        for (int i = 0, j =0; i < RADIX_10; i++)    //收集
        {
            for (int k = 1; k <= radixArrays[i][0]; k++)
                arr[j++] = radixArrays[i][k];
            radixArrays[i][0] = 0;    //复位
        }
    }
}


int main(int argc, const char * argv[]) {
    for (int i = 0; i < 100; ++i) {
        arr[i] = rand() % 100;
    }
    
    RadixSort(100);
    
    for (int i = 0; i < 100; ++i)
        cout << arr[i] << " ";    return 0;
}
