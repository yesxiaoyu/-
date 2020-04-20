// Author : lihongyu
// Time   : 2019-12-23

#include<bits/stdc++.h>
using namespace std;

// leetcode-42 接雨水
// 思路：双索引
// 时间复杂度: O(n)
// 空间复杂度: O(1)
class Solution {
public:
    int trap(vector<int> &height) {
        int len = height.size();
        int l = 0, r = len - 1, left_max = 0, right_max = 0, res = 0;
        while (l < r) {
            if (height[l] < height[r]) {
                if (height[l] > left_max)
                    left_max = height[l];
                else{
                    res += left_max - height[l];
                    l++;
                }
            }
            else {
                if (height[r] > right_max)
                    right_max = height[r];
                else{
                    res += right_max - height[r];
                    r--;
                }
            }
        }
        return res;
    }
};

// TODO:
int main(){

    vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout<<Solution().trap(arr)<<endl; // 输出6

    return 0;
}