// Author : lihongyu
// Time   : 2019-12-09

#include<bits/stdc++.h>
using namespace std;

// leetcode-70 爬楼梯
// 思路：记忆化搜索
// 时间复杂度: O(n)
// 空间复杂度: O(n)

class Solution {
private:
	vector<int> memo;
	int method_num(int n){

		if(n == 0 || n == 1)
			return 1;
		if(memo[n] == -1)
			memo[n] = method_num(n - 1) + method_num(n - 2);
		return memo[n];
	}
public:
    int climbStairs(int n) {
    	memo = vector<int> (n+1, -1);
        return method_num(n);
    }
};

// leetcode-70 爬楼梯
// 思路：动态规划
// 时间复杂度: O(n)
// 空间复杂度: O(n)

class Solution2 {
public:

    int climbStairs(int n) {
    	vector<int> memo(n+1, -1);
    	memo[0] = 1;
    	memo[1] = 1;
    	for(int i = 2; i <= n; i++){
    		memo[i] = memo[i-1] + memo[i-2];
		}

        return memo[n];
    }
};

// TODO：

int main(){

    int n = 3;
    cout<<Solution2().climbStairs(n)<<endl;

    return 0;
}