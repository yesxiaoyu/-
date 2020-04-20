// Author : lihongyu
// Time   : 2020-2-24
// 面试题17. 打印从1到最大的n位数
// 思路：数学
// 时间复杂度: O(n)
// 空间复杂度: O(n)
class Solution {
    public int[] printNumbers(int n) {
        int max = (int)Math.pow(10, n);
        int[] ans = new int[max - 1];
        for(int i = 1 ; i <= max - 1 ; i++){
            ans[i - 1] = i;
        }
        return ans;
    }
}


// TODO: