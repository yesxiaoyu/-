// Author : lihongyu
// Time   : 2019-12-18

#include<bits/stdc++.h>
using namespace std;

// lintcode-382 三角形计数
// 思路：二分搜索
// 时间复杂度: O(n)
// 空间复杂度: O(1)

class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &nums) {
        // write your code here
        if (nums.size() < 3) return 0;
        sort(nums.begin(), nums.end(), greater<int>());
        int res = 0;
        int N = nums.size();
        for (int i = 0; i < N - 2; ++i) {
            int l = i + 1;
            int r = N - 1;
            while (l < r) {
                if (nums[l] + nums[r] <= nums[i]) {
                    --r;
                } else {
                    res += r - l;
                    ++l;
                }
            }
        }
        return res;
    }
};

// TODO：

int main(){
    vector<int> arr = {3, 4, 6, 7};
    cout<<Solution().triangleCount(arr)<<endl;
    return 0;
}