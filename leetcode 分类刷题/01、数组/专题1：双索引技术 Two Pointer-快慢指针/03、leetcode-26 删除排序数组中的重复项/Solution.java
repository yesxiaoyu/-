// Author : lihongyu
// Time   : 2020-2-6
// leetcode-26. 删除排序数组中的重复项
// 思路：数组
// 时间复杂度: O(n)
// 空间复杂度: O(1)

public class Solution {

    public int removeDuplicates(int[] nums) {
        int k = 0;
        for (int i = 0; i < nums.length; i++)
            if (nums[i] != nums[k])
                nums[++k] = nums[i];

        return k+1;
    }

    private static void printArray(int[] nums){
        for(Integer e: nums)
            System.out.print(e + " ");
        System.out.println();
    }
    public static void main(String[] args) {

        int[] nums = {1, 1, 2};
        int res = (new Solution()).removeDuplicates(nums);
        System.out.println(res);
        printArray(nums);

    }
}


// TODO: