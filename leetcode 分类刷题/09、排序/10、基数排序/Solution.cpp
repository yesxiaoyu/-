#include<bits/stdc++.h>
using namespace std;

// LSD首先通过得到最大数字，获取列表中最高位数，
// 然后根据各个不同位数将数据分配到各个桶中，
// 最后将各个数字从桶中取出，完成排序.

int getMax(vector<int>& arr){

    int maxValue = arr[0];
    for(int i : arr)
        if(i > maxValue)
            maxValue = i;
    return maxValue;
}

int getNumberLength(int n){
    if (n == 0) {
        return 1;
    }
    int length = 0;
    for (int i = n; i != 0; i /= 10) {
        length++;
    }
    return length;
}

void raidxSort(vector<int>& arr){

    int maxValue = getMax(arr);
    int maxDigit = getNumberLength(maxValue);

    int mod = 10;
    int dev = 1;

    for (int i = 0; i < maxDigit; i++, dev *= 10, mod *= 10) {
        // 考虑负数的情况，这里扩展一倍队列数，其中 [0-9]对应负数，[10-19]对应正数 (bucket + 10)
        vector<vector<int> > counter = vector<vector<int> >(mod * 2);

        for (int & j : arr) {
            int bucket = ((j % mod) / dev) + mod;
            counter[bucket].emplace_back(j);
        }

        int pos = 0;
        for (vector<int>& bucket: counter) {
            for (int value : bucket) {
                arr[pos++] = value;
            }
        }
    }
}

void printVector(vector<int>& arr){

    for (int i : arr) {
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){

    vector<int> a = {1, 7, 5, 7, 7, 3, 2, 5, 9, 7};
    raidxSort(a);
    printVector(a);
    return 0;
}