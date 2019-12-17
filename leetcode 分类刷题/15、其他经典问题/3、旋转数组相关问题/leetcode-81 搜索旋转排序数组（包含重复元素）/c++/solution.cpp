// Author : lihongyu
// Time   : 2019-12-17

#include<bits/stdc++.h>
using namespace std;

// leetcode-81 搜索旋转排序数组（包含重复元素）
// 思路：二分搜索法，分别考虑当最小值在应该取得前半段、最小值在应该取得后半段以及其他情况
// 时间复杂度: O(logn)
// 空间复杂度: O(1)

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        if (n == 0) return false;
        while (l <= r) {
            if (nums[l] == target) return true;
            int mid = l + (r - l) / 2 ;
            if (nums[mid] == target) return  true;
            if (nums[0] == nums[mid]){
                if (l == n - 1)
                    return false;
                l++;
                if (nums[l] == target) return  true;
                continue;
            }
            if (nums[0] < nums[mid] && (target > nums[mid] || target < nums[0]))
                l = mid + 1;
            else if (target > nums[mid] && target < nums[0])
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false;
    }
};

// TODO：

int main(){
    vector<int> arr = {1};//{2, 5, 6, 0, 0, 1, 2};//{1, 3, 1, 1, 1};
    int target = 0;//0;//3;
    cout<<Solution().search(arr, target)<<endl;
    return 0;
}