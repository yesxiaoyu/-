#include<bits/stdc++.h>
using namespace std;

//通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。
//插入排序和冒泡排序一样，也有一种优化算法，叫做拆半插入。
void insertSort(vector<int>& arr){
    for (int i = 0; i < arr.size(); ++i) {
        int e = arr[i];
        int j;
        for (j = i; j > 0 && arr[j-1] > e; j--)
            arr[j] = arr[j-1];
        arr[j] = e;
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
    insertSort(a);
    printVector(a);
    return 0;
}