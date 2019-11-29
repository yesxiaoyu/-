#include<bits/stdc++.h>
using namespace std;

// 是采用分治法（Divide and Conquer）的一个非常典型的应用。
// 作为一种典型的分而治之思想的算法应用，归并排序的实现由两种方法：
//自上而下的递归（所有递归的方法都可以用迭代重写，所以就有了第 2 种方法）；
//自下而上的迭代；
// 和选择排序一样，归并排序的性能不受输入数据的影响，但表现比选择排序好的多，因为始终都是 O(nlogn) 的时间复杂度。
// 代价是需要额外的内存空间。

class Solution{
public:
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
};

// 使用优化的归并排序算法, 对arr[l...r]的范围进行排序
class Solution2{
public:
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

    // 对arr[l...r]范围的数组进行插入排序
    void insertionSort(vector<int>& arr, int l, int r){

        for( int i = l+1 ; i <= r ; i ++ ) {

            int e = arr[i];
            int j;
            for (j = i; j > l && arr[j-1] > e; j--)
                arr[j] = arr[j-1];
            arr[j] = e;
        }
    }

    void __mergeSort(vector<int>& arr, int l, int r){

        // 优化2: 对于小规模数组, 使用插入排序
        if( r - l <= 15 ){
            insertionSort(arr, l, r);
            return;
        }

        int mid = (l+r)/2;
        __mergeSort(arr, l, mid);
        __mergeSort(arr, mid+1, r);

        // 优化1: 对于arr[mid] <= arr[mid+1]的情况,不进行merge
        // 对于近乎有序的数组非常有效,但是对于一般情况,有一定的性能损失
        if( arr[mid] > arr[mid+1] )
            __merge(arr, l, mid, r);
    }

    void mergeSort(vector<int>& arr){
        __mergeSort(arr, 0, arr.size()-1);
    }
};

// 自底向上的归并排序算法
class Solution3{
public:
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

    void mergeSort(vector<int>& arr){
        int n = arr.size();
        for( int sz = 1; sz < n ; sz += sz )
            for( int i = 0 ; i < n - sz ; i += sz+sz )
                // 对 arr[i...i+sz-1] 和 arr[i+sz...i+2*sz-1] 进行归并
                __merge(arr, i, i+sz-1, min(i+sz+sz-1,n-1) );
    }
};

// 自底向上的归并排序算法的优化
class Solution4{
public:
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

    // 对arr[l...r]范围的数组进行插入排序
    void insertionSort(vector<int>& arr, int l, int r){

        for( int i = l+1 ; i <= r ; i ++ ) {

            int e = arr[i];
            int j;
            for (j = i; j > l && arr[j-1] > e; j--)
                arr[j] = arr[j-1];
            arr[j] = e;
        }
    }

    void mergeSort(vector<int>& arr){
        int n = arr.size();
        // Merge Sort Bottom Up 优化
        // 对于小数组, 使用插入排序优化
        for( int i = 0 ; i < n ; i += 16 )
            insertionSort(arr,i,min(i+15,n-1));

        for( int sz = 16; sz < n ; sz += sz )
            for( int i = 0 ; i < n - sz ; i += sz+sz )
                // 对于arr[mid] <= arr[mid+1]的情况,不进行merge
                if( arr[i+sz-1] > arr[i+sz] )
                    __merge(arr, i, i+sz-1, min(i+sz+sz-1,n-1) );

        // Merge Sort BU 也是一个O(nlogn)复杂度的算法，虽然只使用两重for循环
        // 所以，Merge Sort BU也可以在1秒之内轻松处理100万数量级的数据
        // 注意：不要轻易根据循环层数来判断算法的复杂度，Merge Sort BU就是一个反例
        // 关于这部分陷阱，推荐看我的《玩转算法面试》课程，第二章：《面试中的复杂度分析》
    }
};

// 比较Merge Sort和Merge Sort Bottom Up两种排序算法的性能效率
// 整体而言, 两种算法的效率是差不多的。但是如果进行仔细测试, 自底向上的归并排序会略胜一筹

void printVector(vector<int> arr){

    for (int i = 0; i < arr.size(); ++i) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){

    vector<int> a = {1, 7, 5, 7, 7, 3, 2, 5, 9, 7};
    Solution4().mergeSort(a);
    printVector(a);
    return 0;
}