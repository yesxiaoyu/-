package com.company;
// 33. 搜索旋转排序数组
class Solution {
    public int search(int[] nums, int target) {
        // if (nums.length == 1)
        //     return 0;
        int l = 0, r = nums.length - 1;
        while (l <= r) {
            if (nums[l] == target)
                return l;
            else if (nums[l] > target) {
                if (nums[r] == target)
                    return r;
                else if (nums[r] > target)
                    r--;
                else
                    return -1;
                l++;
            }
            else
                l++;
        }
        return -1;
    }
}
