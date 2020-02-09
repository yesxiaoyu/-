#include<bits/stdc++.h>
using namespace std;

// 首先找到序列最大值
// 开辟最大值个空间，对序列进行计数
// 返回不为零的数据，完成排序

int getMax(vector<int> arr){
    int res = arr[0];
    for(int i : arr)
        if(i > res)
            res = i;
    return res;
}

void countSort(vector<int>& arr){
    int Max = getMax(arr) + 1;
    vector<int> bucket = vector<int>(Max);
    for (int value : arr)
        bucket[value]++;

    int sortedIndex = 0;
    for (int j = 0; j < Max; j++) {
        while (bucket[j] > 0) {
            arr[sortedIndex++] = j;
            bucket[j]--;
        }
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
    countSort(a);
    printVector(a);
    return 0;
}