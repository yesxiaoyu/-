// Author : lihongyu
// Time   : 2019-12-09

#include<bits/stdc++.h>
using namespace std;

// leetcode-120 三角形最小路径和
// 思路：动态规划
// 时间复杂度: O(n)
// 空间复杂度: O(n)

class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
         int n = grid.size();
        assert(n > 0);

        int m = grid[0].size();
        assert(m > 0);

        vector<int> res(m, 0);
        res[0] = grid[0][0];

        for(int j = 1 ; j < m ; j ++)
            res[j] = grid[0][j] + res[j-1];

        for(int i = 1 ; i < n ; i ++){
            res[0] += grid[i][0];
            for(int j = 1 ; j < m ; j ++)
                res[j] = grid[i][j] + min(res[j], res[j-1]);
        }

        return res[m-1];
    }
};


// TODO：

int main(){

//    [
//  [1,3,1],
//  [1,5,1],
//  [4,2,1]
//]    7,因为路径 1→3→1→1→1 的总和最小。

    vector<vector<int> > squareness = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout<<Solution().minPathSum(squareness)<<endl;

    return 0;
}