#include<bits/stdc++.h>
using namespace std;

// 剑指offer-40 最小的k个数
// 解法一，基于patition函数，缺点是改变了数组顺序
// 时间复杂度: O(n)
// 空间复杂度: O(1)

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int>& input, int k) {
        vector<int> res;
        int len = input.size();
        if(len <= 0 || k <= 0 || k > len) return {};
        int l = 0, r = len - 1;
        int index = partition(input, l, r);
        while (index != k-1){
            if (index > k-1)    index = partition(input, l, r-1);
            else    index = partition(input, l+1, r);
        }
        for (int i = 0; i < k; ++i) {
            res.push_back(input[i]);
        }
        return res;
    }

private:
    static int partition(vector<int>& nums, int l, int r){

        int v = nums[l];
        int j = l;
        for(int i = l + 1; i <= r; i++){
            if (nums[i] < v){
                j++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[l], nums[j]);
        return j;
    }
};

// 解法2：红黑树.
// 时间复杂度: O(nlogk)
// 空间复杂度: O(1)

class Solution2{
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {

        int len=input.size();
        if(len<=0||k>len) return vector<int>();

        //仿函数中的greater<T>模板，从大到小排序
        multiset<int, greater<int> > leastNums;
        vector<int>::iterator vec_it=input.begin();
        for(;vec_it!=input.end();vec_it++)
        {
            //将前k个元素插入集合
            if(leastNums.size()<k)
                leastNums.insert(*vec_it);
            else
            {
                //第一个元素是最大值
                multiset<int, greater<int> >::iterator greatest_it=leastNums.begin();
                //如果后续元素<第一个元素，删除第一个，加入当前元素
                if(*vec_it<*(leastNums.begin()))
                {
                    leastNums.erase(greatest_it);
                    leastNums.insert(*vec_it);
                }
            }
        }

        return vector<int>(leastNums.begin(),leastNums.end());

    }
};

void printVector(vector<int> arr){

    for (int i = 0; i < arr.size(); ++i) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> arr = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    printVector(Solution2().GetLeastNumbers_Solution(arr, 2));
    return 0;
}