// Author : lihongyu
// Time   : 2020-2-6
// leetcode-80. 删除排序数组中的重复项 II
// 思路：数组
// 时间复杂度: O(n)
// 空间复杂度: O(1)

public class Solution {
    // 执行用时 : 1 ms , 在所有 Java 提交中击败了 99.79% 的用户
    // 内存消耗 : 37.4 MB , 在所有 Java 提交中击败了 39.28% 的用户
    public int removeDuplicates1(int[] nums) {
        int k = 1, count = 1;
        for (int i = 1; i < nums.length; i++){
            if (nums[i] == nums[i - 1])
                count++;
            else
                count = 1;
            if (count <= 2)
                nums[k++] = nums[i];
        }
        return k;
    }
    // 执行用时 : 1 ms , 在所有 Java 提交中击败了 99.79% 的用户
    // 内存消耗 : 37.1 MB , 在所有 Java 提交中击败了 72.39% 的用户
    public int removeDuplicates(int[] nums) {
        int k = 0;
        for (int i = 0; i < nums.length; ++i)
            if (k < 2 || nums[k - 2] != nums[i])
                nums[k++] = nums[i];
        return k;
    }

    private static void printArray(int[] nums){
        for(Integer e: nums)
            System.out.print(e + " ");
        System.out.println();
    }
    public static void main(String[] args) {

        int[] nums = {0,0,1,1,1,1,2,3,3};//{1, 1, 1, 2, 2, 3};
        int res = (new Solution()).removeDuplicates(nums);
        System.out.println(res);
        printArray(nums);

    }
}


// TODO: