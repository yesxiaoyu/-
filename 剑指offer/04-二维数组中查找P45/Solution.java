// Author : lihongyu
// Time   : 2020-2-13
// leetcode-面试题03. 数组中重复的数字
// 思路：数组
// 时间复杂度: O(n)
// 空间复杂度: O(1)


public class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        if (matrix.length == 0)
            return false;
        int i = 0, j = matrix[0].length - 1;
        while (i < matrix.length && j >= 0) {
            if (matrix[i][j] < target)
                i++;
            else if (matrix[i][j] > target)
                j--;
            else
                return true;
        }
        return false;
    }

    public static void main(String[] args) {

        int[][] matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19},
                {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
        int target = 20; //5;
        boolean res = (new Solution()).findNumberIn2DArray(matrix, target);
        System.out.println(res);

    }
}


// TODO: