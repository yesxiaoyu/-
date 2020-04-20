// Author : lihongyu
// Time   : 2020-2-15
// leetcode-面试题10- I. 斐波那契数列
// 思路：递归、记忆化搜索、动态规划
// 时间复杂度: O(n)
// 空间复杂度: O(1)

import java.util.Arrays;

class Solution {

    public int fib1(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        return fib1(n - 1) + fib1(n - 2);
    }

    public int fib2(int n) {
        int[] memo = new int[n + 1];
        Arrays.fill(memo, -1);

        return fib2(n, memo);
    }

    private int fib2(int n, int[] memo) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (memo[n] == -1)
//            1000000007 是最小的十位质数。模1000000007，可以保证值永远在int的范围内
            memo[n] = (fib2(n - 1, memo) + fib2(n - 2, memo))%1000000007;
        return memo[n];
    }

    public int fib(int n) {
        int[] arr = new int[n + 2];
        Arrays.fill(arr, -1);
        arr[0] = 0;
        arr[1] = 1;
        for (int i = 2; i <= n; ++i)
            arr[i] = (arr[i-1] + arr[i-2])%1000000007 ;
        return arr[n];
    }

    public static void main(String[] args) {

        int n = 45;
        int res = (new Solution()).fib(n);
        System.out.println(res);

    }
}


// TODO: