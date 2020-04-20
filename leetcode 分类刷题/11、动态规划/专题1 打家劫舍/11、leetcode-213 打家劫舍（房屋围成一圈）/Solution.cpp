// Author : lihongyu
// Time   : 2019-12-15

#include<bits/stdc++.h>
using namespace std;

// leetcode-213 打家劫舍（房屋围成一圈）
// 思路：分两种情况,第一种情况下，状态空间只包括nums[0]......nums[n-1]（即不包含最后一个元素）
// 第二种则是nums[1]......nums[n] (即不包含第一个元素)，返回两种情况中的较大者即可
// 时间复杂度: O(n)
// 空间复杂度: O(1)

class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 0)
            return 0;

        if(n == 1)
            return nums[0];

        if(n == 2)
            return max(nums[0], nums[1]);

        return max(rob(nums, 0, nums.size() - 2), rob(nums, 1, nums.size() - 1));
    }

private:
    int rob(const vector<int>& nums, int start, int end){

        int preMax = nums[start];
        int curMax = max(preMax, nums[start+1]);
        for(int i = start + 2 ; i <= end ; i ++){
            int temp = curMax;
            curMax = max(nums[i] + preMax, curMax);
            preMax = temp;
        }

        return curMax;
    }
};

// 时间复杂度: O(n)
// 空间复杂度: O(n)
class Solution2 {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int n=nums.size();
        vector<int>a(n+1),b(n+1);
        for(int i=2;i<n+1;i++){
            a[i]=max(a[i-1],a[i-2]+nums[i-2]);
            b[i]=max(b[i-1],b[i-2]+nums[i-1]);
        }
        return max(a[n],b[n]);
    }
};

// TODO：

int main(){

    vector<int> arr = {1, 2, 3, 1};
    cout<<Solution2().rob(arr)<<endl;

    return 0;
}