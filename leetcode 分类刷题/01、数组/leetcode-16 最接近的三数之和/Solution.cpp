#include<bits/stdc++.h>
using namespace std;

// leetcode-16. 最接近的三数之和：数组的双指针技术
// 时间复杂度: O(n2)
// 空间复杂度: O(1)

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int length = nums.size();
        if(length < 3)
            return INT_MAX;
        sort(nums.begin(), nums.end());
        int gap = INT_MAX, res = INT_MAX;
        int sum = 0;
        for (int i = 0; i < length - 2; ++i) {
            int l = i + 1, r = length - 1;

            while(l < r){
                sum = nums[i] + nums[l] + nums[r];
                if(sum == target)   return target;
                else if(sum < target)    ++l;
                else    --r;

                if (abs(sum - target) < gap){
                    gap = abs(sum - target);
                    res = sum;
                }
            }
        }
        return res;
    }
};

int main(){

//    vector<int> nums = {-1, 2, 1, -4};
    vector<int> nums = {0, 2, 1, -3};
    int target = 1;
    int res = Solution().threeSumClosest(nums, target);
    cout<<res<<endl;
    return 0;
}