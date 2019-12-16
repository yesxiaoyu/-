// Author : lihongyu
// Time   : 2019-12-09

#include<bits/stdc++.h>
using namespace std;

// leetcode-121 买卖股票的最佳时机
// 思路：动态规划 找到状态转移方程范式
// 时间复杂度: O(n)
// 空间复杂度: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp_i_0 = 0, dp_i_1 = INT_MIN;
        for (int i = 0; i < prices.size(); ++i) {
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, -prices[i]);
        }
        return dp_i_0;
    }
};

// TODO：

int main(){
    vector<int> arr = {7, 1, 5, 3, 6, 4};
    cout<<Solution().maxProfit(arr)<<endl;
    return 0;
}