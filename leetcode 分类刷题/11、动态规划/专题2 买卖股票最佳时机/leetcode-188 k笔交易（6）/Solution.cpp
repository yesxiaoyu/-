// Author : lihongyu
// Time   : 2019-12-16

#include<bits/stdc++.h>
using namespace std;

// leetcode-188 k笔交易
// 思路：动态规划 找到状态转移方程
// 范式一次交易由买入和卖出构成，至少需要两天。
// 所以说有效的限制 k 应该不超过 n/2，如果超过，就没有约束作用了，相当于 k = +infinity
// 参考：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/yi-ge-fang-fa-tuan-mie-6-dao-gu-piao-wen-ti-by-l-3/
// https://www.xuebuyuan.com/2104047.html
// 时间复杂度: O(n^2)
// 空间复杂度: O(n^3)

class Solution {
public:
    int maxProfit(int max_k, vector<int>& prices) {
        int n = prices.size();
        if (max_k > n / 2)
            return maxProfit_k_inf(prices);
        vector<vector<vector<int> > > dp;
        dp.resize(n);
        for (int i = 0; i < n; ++i) {
            dp[i].resize(max_k+1);
            for (int j = 0; j < max_k+1; ++j)
                dp[i][j].resize(2);
        }

        for (int i = 0; i < n; i++)
            for (int k = max_k; k >= 1; k--) {
                if (i - 1 == -1) {
                    /* 处理 base case */
                    dp[i][k][0] = 0;
                    dp[i][k][1] = -prices[i];
                    continue;
                }
                dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
                dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);
            }
        return dp[n - 1][max_k][0];
    }

private:
    int maxProfit_k_inf(vector<int>& prices) {
        int dp_i_0 = 0, dp_i_1 = INT_MIN;
        for (int i = 0; i < prices.size(); ++i) {
            int tmp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, tmp - prices[i]);
        }
        return dp_i_0;
    }
};

// 时间复杂度: O(n^2)
// 空间复杂度: O(n^2)
class Solution2 {
public:
    int maxProfit(int max_k, vector<int>& prices) {
        int n = prices.size();
        if (max_k > n / 2)
            return maxProfit_k_inf(prices);
        vector<vector<int> > dp0, dp1;
        dp0.resize(n);
        dp1.resize(n);
        for (int i = 0; i < n; ++i) {
            dp0[i].resize(max_k+1);
            dp1[i].resize(max_k+1);
        }

        for (int i = 0; i < n; i++)
            for (int k = max_k; k >= 1; k--) {
                if (i - 1 == -1) {
                    /* 处理 base case */
                    dp0[i][k] = 0;
                    dp1[i][k] = -prices[i];
                    continue;
                }
                dp0[i][k] = max(dp0[i-1][k], dp1[i-1][k] + prices[i]);
                dp1[i][k] = max(dp1[i-1][k], dp0[i-1][k-1] - prices[i]);
            }
        return dp0[n - 1][max_k];
    }

private:
    int maxProfit_k_inf(vector<int>& prices) {
        int dp_i_0 = 0, dp_i_1 = INT_MIN;
        for (int i = 0; i < prices.size(); ++i) {
            int tmp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, tmp - prices[i]);
        }
        return dp_i_0;
    }
};

// TODO：

int main(){
    vector<int> arr = {3, 2, 6, 5, 0, 3};
    int k = 2;
    cout<<Solution2().maxProfit(k, arr)<<endl;
    return 0;
}