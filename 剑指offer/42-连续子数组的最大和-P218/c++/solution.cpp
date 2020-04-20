// Author : lihongyu
// Time   : 2019-12-05

#include<bits/stdc++.h>
using namespace std;

// 剑指offer-42 连续子数组的最大和
// 思路：当前元素之和小于0，则舍弃之前元素.
//      默认返回数组中最小元素，以防数组全为负数
// 时间复杂度: O(n)
// 空间复杂度: O(1)

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int>& arr) {
        int curSum = 0, allSum = FindMin(arr);
        for (int i : arr) {
            if (curSum <= 0)
                curSum = i;
            else
                curSum += i;
            if (curSum > allSum)
                allSum = curSum;
        }
        return allSum;
    }

private:
    int FindMin(vector<int>& arr){
        int min = arr[0];
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] > min)   min = arr[i];
        }
        return min;
    }
};

//TODO:动态规划实现

int main(){
    vector<int> arr = {-2,-8,-1,-5,-9};//{1, -2, 3, 10, -4, 7, 2, -5};
    cout<<Solution().FindGreatestSumOfSubArray(arr)<<endl;
    return 0;
}