// Author : lihongyu
// Time   : 2019-12-13

#include<bits/stdc++.h>
using namespace std;

// 剑指offer57-和为S的两个数字-P280
// 思路：双索引技术-对撞指针
// 时间复杂度: O(n)
// 空间复杂度: O(1)

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int>& arr, int sum) {
        vector<int> res = {};
        if (arr.size() < 2) return res;
        int l = 0, r = arr.size()-1;
        int maxMul = INT_MAX;
        while (l < r) {
            int curSum = arr[l] + arr[r];
            if (curSum == sum) {
                if (arr[l] * arr[r] < maxMul) {
                    maxMul = arr[l] * arr[r];
                    res.clear();
                    res.push_back(arr[l]);
                    res.push_back(arr[r]);
                }
                l++;
            } else if (curSum < sum){
                l++;
            } else{
                r--;
            }
        }
        return res;
    }
};

void printVector(vector<int>& arr){

    for (int i : arr) {
        cout<<i<<" ";
    }
    cout<<endl;
}

// TODO：其实不加两数相乘取最小的判断仍然能够通过，因为从两端到中间顺序添加，而两端相乘一定小于中间两数相乘的结果.

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};//{1, 2, 4, 7, 11, 15};
    int num = 21;//15;
    vector<int> res = Solution().FindNumbersWithSum(arr, num);
    printVector(res);

    return 0;
}