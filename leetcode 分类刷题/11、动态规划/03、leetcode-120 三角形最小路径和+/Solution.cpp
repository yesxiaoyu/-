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
    int minimumTotal(vector<vector<int> >& triangle) {
        for (int i = triangle.size() - 2; i >= 0; i--)
	        for (int j = 0; j < triangle[i].size(); j++)
	            triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
    	return triangle[0][0];
    }
};


// TODO：

int main(){

//    [
//     [2],
//    [3,4],
//   [6,5,7],
//  [4,1,8,3]
//]自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

    vector<vector<int> > triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout<<Solution().minimumTotal(triangle)<<endl;

    return 0;
}