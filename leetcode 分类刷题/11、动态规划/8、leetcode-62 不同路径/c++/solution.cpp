// Author : lihongyu
// Time   : 2019-12-09

#include<bits/stdc++.h>
using namespace std;

// leetcode-62 不同路径
// 思路：动态规划
// 时间复杂度: O(n2)
// 空间复杂度: O(n2)

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for(int i = 1; i < m; i ++)
            for(int j = 1; j < n; j ++)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp[m - 1][n - 1];
    }
};

// TODO：

 int main() {
 	int m = 7, n = 3;
 	cout<<Solution().uniquePaths(m, n)<<endl;

 	return 0;
 }