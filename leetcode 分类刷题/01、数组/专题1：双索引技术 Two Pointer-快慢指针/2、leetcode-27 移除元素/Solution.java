// Author : lihongyu
// Time   : 2020-2-5
// leetcode-27. 移除元素
// 思路：数组
// 时间复杂度: O(n)
// 空间复杂度: O(1)

public class Solution {

    public int removeElement(int[] nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != val)
                nums[k++] = nums[i];
        }
        return k;
    }

    private static void printArray(int[] nums){
        for(Integer e: nums)
            System.out.print(e + " ");
        System.out.println();
    }
    public static void main(String[] args) {

        int[] nums = {3, 2, 2, 3};
        int val = 3;
        int res = (new Solution()).removeElement(nums, val);
        System.out.println(res);
        printArray(nums);

    }
}


// TODO: