#include<bits/stdc++.h>
using namespace std;

// 是采用分治法（Divide and Conquer）的一个非常典型的应用。
// 作为一种典型的分而治之思想的算法应用，归并排序的实现由两种方法：
//自上而下的递归（所有递归的方法都可以用迭代重写，所以就有了第 2 种方法）；
//自下而上的迭代；
// 和选择排序一样，归并排序的性能不受输入数据的影响，但表现比选择排序好的多，因为始终都是 O(nlogn) 的时间复杂度。
// 代价是需要额外的内存空间。

// 将arr[l...mid]和arr[mid+1...r]两部分进行归并
void __merge(vector<int>& arr, int l, int mid, int r){

    // VS不支持动态长度数组, 即不能使用 T aux[r-l+1]的方式申请aux的空间
    // 使用new的方式申请aux空间, 不要忘了在__merge函数的最后, delete掉申请的空间:)
    int aux[r-l+1];
    //T *aux = new T[r-l+1];

    for( int i = l ; i <= r; i ++ )
        aux[i-l] = arr[i];

    // 初始化，i指向左半部分的起始索引位置l；j指向右半部分起始索引位置mid+1
    int i = l, j = mid+1;
    for( int k = l ; k <= r; k ++ ){

        if( i > mid ){  // 如果左半部分元素已经全部处理完毕
            arr[k] = aux[j-l]; j ++;
        }
        else if( j > r ){  // 如果右半部分元素已经全部处理完毕
            arr[k] = aux[i-l]; i ++;
        }
        else if( aux[i-l] < aux[j-l] ) {  // 左半部分所指元素 < 右半部分所指元素
            arr[k] = aux[i-l]; i ++;
        }
        else{  // 左半部分所指元素 >= 右半部分所指元素
            arr[k] = aux[j-l]; j ++;
        }
    }
//    delete[] aux;
}

void __mergeSort(vector<int>& arr, int l, int r){
    if( l >= r )
        return;

    int mid = (l+r)/2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid+1, r);
    __merge(arr, l, mid, r);
}

void mergeSort(vector<int>& arr){
    __mergeSort(arr, 0, arr.size()-1);
}

void printVector(vector<int> arr){

    for (int i = 0; i < arr.size(); ++i) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){

    vector<int> a = {1, 7, 5, 7, 7, 3, 2, 5, 9, 7};
    mergeSort(a);
    printVector(a);
    return 0;
}