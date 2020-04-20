// Author : lihongyu
// Time   : 2019-12-07

#include<bits/stdc++.h>
using namespace std;

// leetcode-349 两个数组的交集
// 思路：使用集合set过滤重复元素
// 时间复杂度: O(nlogn)
// 空间复杂度: O(n)

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> sets(nums1.begin(), nums1.end());
        vector<int> res;
        for(int num : nums2) {
            if(sets.find(num) != sets.end()) {
                if(find(res.begin(), res.end(), num) == res.end())
                    res.emplace_back(num);
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

// TODO：

int main(){
    vector<int> arr1 = {4, 9, 5}, arr2 = {9, 4, 9, 8, 4}, res;
    res = Solution().uniqueMorseRepresentations(arr);
	printVector(res);
    return 0;
}