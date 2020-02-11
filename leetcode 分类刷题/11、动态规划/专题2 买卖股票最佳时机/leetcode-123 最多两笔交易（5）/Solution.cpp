// Author : lihongyu
// Time   : 2019-12-16

#include<bits/stdc++.h>
using namespace std;

// leetcode-123 最多两笔交易
// 思路：动态规划 找到状态转移方程范式
// 参考：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/yi-ge-fang-fa-tuan-mie-6-dao-gu-piao-wen-ti-by-l-3/
// 时间复杂度: O(n)
// 空间复杂度: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp_i_1_0 = 0, dp_i_1_1 = INT_MIN;
        int dp_i_2_0 = 0, dp_i_2_1 = INT_MIN;
        for (int i = 0; i < prices.size(); ++i) {
            dp_i_2_0 = max(dp_i_2_0, dp_i_2_1 + prices[i]);
            dp_i_2_1 = max(dp_i_2_1, dp_i_1_0 - prices[i]);
            dp_i_1_0 = max(dp_i_1_0, dp_i_1_1 + prices[i]);
            dp_i_1_1 = max(dp_i_1_1, -prices[i]);
        }
        return dp_i_2_0;
    }
};

// TODO：

int main(){
    vector<int> arr = {3, 3, 5, 0, 0, 3, 1, 4};
    cout<<Solution().maxProfit(arr)<<endl;
    return 0;
}