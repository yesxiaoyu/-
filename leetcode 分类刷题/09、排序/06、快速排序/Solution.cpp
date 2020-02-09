#include<bits/stdc++.h>
using namespace std;

// 是采用分治法（Divide and Conquer）的一个非常典型的应用。
// 作为一种典型的分而治之思想的算法应用，归并排序的实现由两种方法：
//自上而下的递归（所有递归的方法都可以用迭代重写，所以就有了第 2 种方法）；
//自下而上的迭代；
// 从数列中挑出一个元素，称为 “基准”（pivot）
// 重新排序数列，所有元素比基准值小的摆放在基准前面，所有元素比基准值大的摆在基准的后面（相同的数可以到任一边）。
//   在这个分区退出之后，该基准就处于数列的中间位置。这个称为分区（partition）操作
// 递归地（recursive）把小于基准值元素的子数列和大于基准值元素的子数列排序

class Solution{
public:
    // 对arr[l...r]部分进行partition操作
    // 返回p, 使得arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
    int __partition(vector<int>& arr, int l, int r){

        int v = arr[l];

        int j = l; // arr[l+1...j] < v ; arr[j+1...i) > v
        for( int i = l + 1 ; i <= r ; i ++ )
            if( arr[i] < v ){
                j ++;
                swap( arr[j] , arr[i] );
            }

        swap( arr[l] , arr[j]);

        return j;
    }

    // 对arr[l...r]部分进行快速排序
    void __quickSort(vector<int>& arr, int l, int r){

        if( l >= r )
            return;

        int p = __partition(arr, l, r);
        __quickSort(arr, l, p-1 );
        __quickSort(arr, p+1, r);
    }

    void quickSort(vector<int>& arr){

        int n = arr.size();
        __quickSort(arr, 0, n-1);
    }
};

// 针对近乎有序的输入数据，对快速排序算法进行优化
class Solution2{
public:
    // 对arr[l...r]部分进行partition操作
    // 返回p, 使得arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
    int __partition(vector<int>& arr, int l, int r){

        // 改进1：随机在arr[l...r]的范围中, 选择一个数值作为标定点pivot
        swap( arr[l] , arr[rand()%(r-l+1)+l] );

        int v = arr[l];
        int j = l;
        for( int i = l + 1 ; i <= r ; i ++ )
            if( arr[i] < v ){
                j ++;
                swap( arr[j] , arr[i] );
            }

        swap( arr[l] , arr[j]);

        return j;
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

    // 对arr[l...r]部分进行快速排序
    void __quickSort(vector<int>& arr, int l, int r){

        // 改进点2：对于小规模数组, 使用插入排序进行优化
        if( r - l <= 15 ){
            insertionSort(arr,l,r);
            return;
        }

        int p = __partition(arr, l, r);
        __quickSort(arr, l, p-1 );
        __quickSort(arr, p+1, r);
    }

    void quickSort(vector<int>& arr){
        int n = arr.size();
        __quickSort(arr, 0, n-1);
    }
};

// 双路快速排序可以解决处理输入数据为近乎有序的数组和未排序的序列包含大量相同元素的数组
class Solution3{
public:
    // 双路快速排序的partition
    // 返回p, 使得arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
    int __partition(vector<int>& arr, int l, int r){

        // 随机在arr[l...r]的范围中, 选择一个数值作为标定点pivot
        swap( arr[l] , arr[rand()%(r-l+1)+l] );
        int v = arr[l];

        // arr[l+1...i) <= v; arr(j...r] >= v
        int i = l+1, j = r;
        while( true ){
            // 注意这里的边界, arr[i] < v, 不能是arr[i] <= v
            // 思考一下为什么?
            while( i <= r && arr[i] < v )
                i ++;

            // 注意这里的边界, arr[j] > v, 不能是arr[j] >= v
            // 思考一下为什么?
            while( j >= l+1 && arr[j] > v )
                j --;

            if( i > j )
                break;

            swap( arr[i] , arr[j] );
            i ++;
            j --;
        }

        swap( arr[l] , arr[j]);

        return j;
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

    // 对arr[l...r]部分进行快速排序
    void __quickSort(vector<int>& arr, int l, int r){

        // 对于小规模数组, 使用插入排序进行优化
        if( r - l <= 15 ){
            insertionSort(arr,l,r);
            return;
        }

        // 调用双路快速排序的partition
        int p = __partition(arr, l, r);
        __quickSort(arr, l, p-1 );
        __quickSort(arr, p+1, r);
    }
    void quickSort(vector<int>& arr){

        int n = arr.size();
        __quickSort(arr, 0, n-1);
    }
};

// 对于包含有大量重复数据的数组, 三路快排有巨大的优势
// 对于一般性的随机数组和近乎有序的数组, 三路快排的效率虽然不是最优的, 但是是在非常可以接受的范围
// java中，三路快排是默认的语言库函数中使用的排序算法
class Solution4{
public:

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

    void __quickSort(vector<int>& arr, int l, int r){

        // 对于小规模数组, 使用插入排序进行优化
        if( r - l <= 15 ){
            insertionSort(arr,l,r);
            return;
        }

        // 随机在arr[l...r]的范围中, 选择一个数值作为标定点pivot
        swap( arr[l], arr[rand()%(r-l+1)+l ] );

        int v = arr[l];

        int lt = l;     // arr[l+1...lt] < v
        int gt = r + 1; // arr[gt...r] > v
        int i = l+1;    // arr[lt+1...i) == v
        while( i < gt ){
            if( arr[i] < v ){
                swap( arr[i], arr[lt+1]);
                i ++;
                lt ++;
            }
            else if( arr[i] > v ){
                swap( arr[i], arr[gt-1]);
                gt --;
            }
            else{ // arr[i] == v
                i ++;
            }
        }

        swap( arr[l] , arr[lt] );

        __quickSort(arr, l, lt-1);
        __quickSort(arr, gt, r);
    }

    void quickSort(vector<int>& arr){

        int n = arr.size();
        __quickSort(arr, 0, n-1);
    }
};

void printVector(vector<int> arr){

    for (int i = 0; i < arr.size(); ++i) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){

    vector<int> a = {1, 7, 5, 7, 7, 3, 2, 5, 9, 7};
    Solution4().quickSort(a);
    printVector(a);
    return 0;
}