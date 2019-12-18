// Author : lihongyu
// Time   : 2019-12-17

#include<bits/stdc++.h>
using namespace std;

// lintcode-191 乘积最大连续子序列
// 思路：编程之美-P181，没看懂
// 时间复杂度: O(n)
// 空间复杂度: O(n)

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An integer
     */
    int maxProduct(vector<int> &nums) {
        // write your code here
        if (nums.size() == 1)
            return nums[0];
        int n = nums.size();
        int res = INT_MIN;
        vector<int> s = vector<int>(n + 1);
        vector<int> t = vector<int>(n + 1);
        s[0] = 1;
        for (int i = 1; i < n + 1; ++i) {
            s[i] = s[i - 1] * nums[i - 1];
            if (nums[i - 1] > res)
                res = nums[i - 1];
        }
        for (int i = 0; i < n + 1; ++i)
            t[i] = t[i + 1] * nums[i];

        for (int i = 1; i < n; ++i)
            res = max(res, max(s[i - 1], t[i + 1]));

        return res;
    }
};

// 思路：动态规划，由于存在负数，那么会导致最大的变最小的，最小的变最大的。
// 因此还需要维护当前最小值imin，当负数出现时则imax与imin进行交换再进行下一步计算
// 时间复杂度: O(n)
// 空间复杂度: O(1)

class Solution2 {
public:
    /**
     * @param nums: An array of integers
     * @return: An integer
     */
    int maxProduct(vector<int> &nums) {
        int maxV = INT_MIN, imax = 1, imin = 1;
        for(int num : nums){
            if(num < 0)
              swap(imax, imin);

            imax = max(imax*num, num);
            imin = min(imin*num, num);

            maxV = max(maxV, imax);
        }
        return maxV;
    }
};

// TODO：

int main(){
    vector<int> arr = {1, 0, -1, 2, 3, -5, -2};// ->60   {2, 3, -2, 4};
    cout<<Solution2().maxProduct(arr)<<endl;
    return 0;
}