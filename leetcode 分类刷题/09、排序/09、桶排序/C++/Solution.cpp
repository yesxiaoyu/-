#include<bits/stdc++.h>
using namespace std;

// 首先找到序列最大值与最小值，
// 然后利用映射函数将数据分配到各个桶中，
// 最后对每个桶进行排序，比如使用插入排序.

void insertSort(vector<int>& arr){
    for (int i = 0; i < arr.size(); ++i) {
        int e = arr[i];
        int j;
        for (j = i; j > 0 && arr[j-1] > e; j--)
            arr[j] = arr[j-1];
        arr[j] = e;
    }
}

void bucketSort(vector<int>& arr){

    int bucketSize = 5;     // 假定分5个桶
    int minValue = arr[0];
    int maxValue = arr[0];

    for(int i : arr){
        if(i > maxValue)
            maxValue = i;
        else if(i < minValue)
            minValue = i;
    }

    int bucketCount = (int) floor((maxValue - minValue) / bucketSize) + 1;
    vector<vector<int> > buckets = vector<vector<int> >(bucketCount);
    // 利用映射函数将数据分配到各个桶中
    for (int i = 0; i < arr.size(); i++) {
        int index = (int) floor((arr[i] - minValue) / bucketSize);
        buckets[index].emplace_back(arr[i]);
    }

    int arrIndex = 0;
    for (vector<int> bucket : buckets) {
        if (bucket.size() <= 0) {
            continue;
        }
        // 对每个桶进行排序，这里使用了插入排序
        insertSort(bucket);
        for (int value : bucket) {
            arr[arrIndex++] = value;
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
    bucketSort(a);
    printVector(a);
    return 0;
}