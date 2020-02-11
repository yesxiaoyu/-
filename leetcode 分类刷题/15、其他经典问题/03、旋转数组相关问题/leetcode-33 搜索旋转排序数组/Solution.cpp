// Author : lihongyu
// Time   : 2019-12-17

#include<bits/stdc++.h>
using namespace std;

// leetcode-33 搜索旋转排序数组
// 思路：二分搜索法，分别考虑当最小值在应该取得前半段、最小值在应该取得后半段以及其他情况
// 时间复杂度: O(logn)
// 空间复杂度: O(1)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2 ;
            if (nums[mid] == target) return  mid;
            if (nums[0] <= nums[mid] && (target > nums[mid] || target < nums[0]))
                l = mid + 1;
            else if (target > nums[mid] && target < nums[0])
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
};

// TODO：

int main(){
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};//{1, 3};
    int target = 0;
    cout<<Solution().search(arr, target)<<endl;
    return 0;
}