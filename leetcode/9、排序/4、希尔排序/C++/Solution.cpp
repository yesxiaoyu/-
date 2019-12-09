#include<bits/stdc++.h>
using namespace std;

// 也称递减增量排序算法，是插入排序的一种更高效的改进版本，但希尔排序是非稳定排序算法
// 希尔排序是基于插入排序的以下两点性质而提出改进方法的：
//  插入排序在对几乎已经排好序的数据操作时，效率高，即可以达到线性排序的效率；
//  但插入排序一般来说是低效的，因为插入排序每次只能将数据移动一位
// 先将整个待排序的记录序列分割成为若干子序列分别进行直接插入排序，待整个序列中的记录“基本有序”时，再对全体记录进行依次直接插入排序。
void shellSort(vector<int>& arr){
    // 计算 increment sequence: 1, 4, 13, 40, 121, 364, 1093...
    int n = arr.size();
    int h = 1;
    while( h < n/3 )
        h = 3 * h + 1;

    while( h >= 1 ) {
        // h-sort the array
        for (int i = h; i < n; i++) {
            // 对 arr[i], arr[i-h], arr[i-2*h], arr[i-3*h]... 使用插入排序
            int e = arr[i];
            int j;
            for (j = i; j >= h && e < arr[j - h]; j -= h)
                arr[j] = arr[j - h];
            arr[j] = e;
        }
        h /= 3;
    }
}

void printVector(vector<int> arr){

    for (int i = 0; i < arr.size(); ++i) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){

    vector<int> a = {1, 7, 5, 7, 7, 3, 2, 5, 9, 7};
    shellSort(a);
    printVector(a);
    return 0;
}