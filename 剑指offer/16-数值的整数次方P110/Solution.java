// Author : lihongyu
// Time   : 2020-2-24
// leetcode-50 面试题16. 数值的整数次方
// 思路：递归
// 时间复杂度: O(n)
// 空间复杂度: O(n)
class Solution {
    public double myPow(double x, int n) {
        long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        double ans = 1;
        double current_product = x;
        for (long i = N; i > 0; i /= 2) {
            if ((i % 2) == 1) {
                ans = ans * current_product;
            }
            current_product = current_product * current_product;
        }
        return ans;
    }
};


// TODO: