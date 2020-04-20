// Author : lihongyu
// Time   : 2020-2-13
// leetcode-面试题03. 数组中重复的数字
// 思路：数组
// 时间复杂度: O(n)
// 空间复杂度: O(1)


public class Solution {
    private void swap(int[] nums, int i, int j){
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }

    public int findRepeatNumber(int[] nums) {
        for (int i = 0; i < nums.length; i++){
            while ( nums[i] != i ) {
                if ( nums[i] == nums[nums[i]] )
                    return nums[i];
                else swap(nums, nums[i], i);
            }
        }
        throw new IllegalArgumentException("数组中不存在重复数字！");
    }

    public static void main(String[] args) {

        int[] nums = {2, 3, 1, 0, 2, 5, 3};
        int res = (new Solution()).findRepeatNumber(nums);
        System.out.println(res);

    }
}


// TODO: