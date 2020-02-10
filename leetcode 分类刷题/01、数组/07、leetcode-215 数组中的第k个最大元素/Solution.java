// Author : lihongyu
// Time   : 2020-2-7
// leetcode-215. 数组中的第K个最大元素
// 思路：数组
// 时间复杂度: O(n)
// 空间复杂度: O(1)

import java.util.Arrays;
import java.util.Collections;
import java.util.stream.Collectors;
import java.util.stream.IntStream;


public class Solution {
    public int findKthLargest(int[] nums, int k) {
        Integer[] Nums= IntStream.of(nums).boxed().collect(Collectors.toList()).toArray(new Integer[0]);
        Arrays.sort(Nums, Collections.reverseOrder());
//        Arrays.sort(nums);
        return Nums[k-1];
    }

    public static void main(String[] args) {

        int[] nums = {3, 2, 1, 5, 6, 4};
        int k = 2;
        int res = (new Solution()).findKthLargest(nums, k);
        System.out.println(res);

    }
}


// TODO: