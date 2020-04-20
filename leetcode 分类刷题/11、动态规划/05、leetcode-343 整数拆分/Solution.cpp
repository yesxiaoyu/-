// Author : lihongyu
// Time   : 2019-12-09

#include<bits/stdc++.h>
using namespace std;

// leetcode-343. 整数拆分 Integer Break
// 思路：动态规划
// 时间复杂度: O(n2)
// 空间复杂度: O(n)

class Solution {
public:
    int integerBreak(int n) {
    	vector<int> memo(n+1, -1);
    	memo[1] = 1;
    	for(int i=2; i<=n; i++){
    		for(int j=1; j<=i-1; j++){
    			memo[i] = max(memo[i], max(j*(i-j), j*memo[i-j]));
			}
		}
		return memo[n];
    }
};

// TODO：

 int main() {
 	int num = 10;
 	cout<<Solution().integerBreak(num)<<endl;

 	return 0;
 }