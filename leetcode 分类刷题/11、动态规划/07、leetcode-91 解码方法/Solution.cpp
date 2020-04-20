// Author : lihongyu
// Time   : 2019-12-09

#include<bits/stdc++.h>
using namespace std;

// leetcode-279 完全平方数
// 思路：动态规划
// 时间复杂度: O(n2)
// 空间复杂度: O(n)

class Solution {
public:
    int numSquares(int n) {
        vector<int> mem(n + 1, INT_MAX);
        mem[0] = 0;
        for(int i = 1; i <= n ; i ++)
            for(int j = 1 ; i - j * j >= 0 ; j ++)
                mem[i] = min(mem[i], 1 + mem[i - j * j]);

        return mem[n];
    }
};

// TODO：

 int main() {
 	int num = 13;
 	cout<<Solution().numSquares(num)<<endl;

 	return 0;
 }