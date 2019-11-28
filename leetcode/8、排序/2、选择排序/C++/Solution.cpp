#include<bits/stdc++.h>
using namespace std;

//每次都在未排序数组中找到最小的元素，放到起始位置。
void selectionSort(vector<int>& arr){
    for (int i = 0; i < arr.size(); ++i) {
        int minIndex = i;
        for (int j = i+1; j < arr.size(); ++j)
            if (arr[j] < arr[minIndex])
                minIndex = j;
        swap(arr[i], arr[minIndex]);
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
    selectionSort(a);
    printVector(a);
    return 0;
}