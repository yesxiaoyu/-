// Author : lihongyu
// Time   : 2019-12-08

#include<bits/stdc++.h>
using namespace std;

// 剑指offer-51 数组中的逆序对
// 思路：顺序扫描整个数组，比较该数字与其后面数字大小.
// 过慢，牛客通过50%

// 时间复杂度: O(n2)
// 空间复杂度: O(1)

class Solution {
public:
    int InversePairs(vector<int> data) {
        int res = 0;
        for (int i = 0; i < data.size(); ++i) {
            for (int j = i+1; j < data.size(); ++j) {
                if (data[j] < data[i])
                    res++;
            }
        }
        return res;
    }
};

// 思路：归并排序的改进，把数据分成前后两个数组(递归分到每个数组仅有一个数据项)，
//合并数组，合并时，出现前面的数组值array[i]大于后面数组值array[j]时；则前面
//数组array[i]~array[mid]都是大于array[j]的，count += mid+1 - i
//参考剑指Offer，但是感觉剑指Offer归并过程少了一步拷贝过程。
//还有就是测试用例输出结果比较大，对每次返回的count mod(1000000007)求余
// 1000000007 是最小的十位质数。模1000000007，可以保证值永远在int的范围内。

// 时间复杂度: O(nlogn)
// 空间复杂度: O(n)

class Solution2 {
public:
    long countRes=0 ;
    int InversePairs(vector<int>& data) {
        //countRes = 0;
        if(data.size() <=1)
            return 0;
        MergeSort(data,0,data.size()-1);
        return countRes%1000000007 ;
    }

    void MergeSort(vector<int>& data,int first,int end){
        if(first < end){
            int mid = (first + end)/2;
            MergeSort(data,first,mid);
            MergeSort(data,mid+1,end);
            vector<int> tmp;
            MergeArray(data,first,mid,end,tmp);
        }
    }
    void MergeArray(vector<int>& data,int first,int mid,int end,vector<int> &tmp){
        int i = first;//int m = mid;
        int j = mid + 1;//int n = end;

        while(i<=mid && j<=end){
            if(data[i] > data[j]){
                tmp.push_back(data[i++]);
                countRes += end - j+1;//更新逆序对数
            }
            else{
                tmp.push_back(data[j++]);
            }
        }
        while(i<=mid)
            tmp.push_back(data[i++]);
        while (j<=end)
            tmp.push_back(data[j++]);

        //更新data数组
        int k = 0;
        for (int i = first; i <= end &&k<tmp.size(); i++)
            data[i] = tmp[k++];
    }
};

// TODO：未调通

class MergeSorts{
public:
    void mergeSort(vector<int>& arr){
        _mergeSort(arr, 0, arr.size()-1);
    }

    void printVector(vector<int> arr){

        for (int i : arr) {
            cout<<i<<" ";
        }
        cout<<endl;
}

private:
     // 将arr[l...mid]和arr[mid+1...r]两部分进行归并
    void _merge(vector<int>& arr, int l, int mid, int r) {
        int i = l, j = mid + 1;
        vector<int> tmp;
        while (i <= mid && j <= r){
            if (arr[i] > arr[j])    tmp.push_back(arr[i++]);
            else    tmp.push_back(arr[j++]);
        }
        while (i <= mid)    tmp.push_back(arr[i++]);
        while (j <= r)      tmp.push_back(arr[j++]);

        //更新data数组
        int k = 0;
        for (int i = l; i <= r &&k<tmp.size(); i++)
            arr[i] = tmp[k++];
    }

    void _mergeSort(vector<int>& arr, int l, int r) {
        if (l < r){
            int mid = (r - l) / 2;

            _mergeSort(arr, l, mid);
            _mergeSort(arr, mid+1, r);
            _merge(arr, l, mid, r);
        }

    }
};

int main(){
    vector<int> arr = {7, 5, 6, 4};
//    cout<<Solution2().InversePairs(arr)<<endl;
    MergeSorts().mergeSort(arr);
    MergeSorts().printVector(arr);
    return 0;
}