// Author : lihongyu
// Time   : 2019-12-09

#include<bits/stdc++.h>
using namespace std;

// leetcode-63 不同路径(有路障)
// 思路：动态规划
// 时间复杂度: O(n2)
// 空间复杂度: O(n2)

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(!m) return 0;

        int n = obstacleGrid[0].size();
        if(!n || obstacleGrid[0][0])
            return 0;

         vector<vector<int>> dp(m, vector< int>(n, -1));
//        unsigned int dp[m][n];
        dp[0][0] = 1;
        for(int j = 1; j < n; j ++)
            if(obstacleGrid[0][j])
                dp[0][j] = 0;
            else
                dp[0][j] = dp[0][j - 1];

        for(int i = 1; i < m; i ++)
            if(obstacleGrid[i][0])
                dp[i][0] = 0;
            else
                dp[i][0] = dp[i - 1][0];

        for(int i = 1; i < m; i ++)
            for(int j = 1; j < n; j ++)
                if(obstacleGrid[i][j])
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp[m - 1][n - 1];
    }
};

// TODO：

 int main() {

//     输入:
//[
//  [0,0,0],
//  [0,1,0],
//  [0,0,0]
//]    输出: 2
 	vector<vector<int> > obsGird = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
 	cout<<Solution().uniquePathsWithObstacles(obsGird)<<endl;

 	return 0;
 }