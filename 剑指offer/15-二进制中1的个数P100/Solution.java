// Author : lihongyu
// Time   : 2020-2-24
// leetcode-191 二进制中1的个数
// 思路：位运算
// 时间复杂度: O(n)
// 空间复杂度: O(n)
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int count = 0;
         
         while (n != 0){
            count++;
            n = (n-1) & n;
         }
         return count;
    }
}


// TODO: