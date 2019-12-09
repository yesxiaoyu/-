#include<bits/stdc++.h>
using namespace std;

//比较相邻的元素，如果他们的顺序错误就把他们交换过来
void bubbleSort(vector<int>& arr){
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = i+1; j < arr.size(); ++j)
            if(arr[i] > arr[j])
                swap(arr[i], arr[j]);
    }
}

void bubbleSortUp(vector<int>& arr){
    int n = arr.size();
    bool swapped;
    //int newn; // 理论上,可以使用newn进行优化,但实际优化效果较差
    do{
        swapped = false;
        //newn = 0;
        for( int i = 1 ; i < n ; i ++ )
            if( arr[i-1] > arr[i] ){
                swap( arr[i-1] , arr[i] );
                swapped = true;

                // 可以记录最后一次的交换位置,在此之后的元素在下一轮扫描中均不考虑
                // 实际优化效果较差,因为引入了newn这个新的变量
                //newn = n;
            }
        //n = newn;

        // 优化,每一趟Bubble Sort都将最大的元素放在了最后的位置
        // 所以下一次排序,最后的元素可以不再考虑
        // 理论上,newn的优化是这个优化的复杂版本,应该更有效
        // 实测,使用这种简单优化,时间性能更好
        n --;

    }while(swapped);
}

void printVector(vector<int> arr){

    for (int i = 0; i < arr.size(); ++i) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){

    vector<int> a = {1, 7, 5, 7, 7, 3, 2, 5, 9, 7};
    bubbleSortUp(a);
    printVector(a);
    return 0;
}