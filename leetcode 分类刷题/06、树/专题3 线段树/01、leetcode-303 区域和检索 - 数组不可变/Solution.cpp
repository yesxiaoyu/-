// Author : lihongyu
// Time   : 2019-12-16

#include<bits/stdc++.h>
using namespace std;

// leetcode-303 区域和检索 - 数组不可变
// 思路：使用数组的效率高于线段树
// 时间复杂度: O(n)
// 空间复杂度: O(1)

class NumArray {
public:
    NumArray(vector<int>& nums) {
        sum = vector<int>(nums.size() + 1);
        sum[0] = 0;
        for (int i = 1; i < sum.size(); ++i)
            sum[i] = sum[i - 1] + nums[i - 1];
    }

    int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];
    }

private:
    vector<int> sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

// TODO：

int main(){
    vector<int> arr = {-2, 0, 3, -5, 2, -1};
    NumArray* na = new NumArray(arr);
    cout<<na->sumRange(0, 2)<<endl;
    cout<<na->sumRange(2, 5)<<endl;
    cout<<na->sumRange(0, 5)<<endl;
    return 0;
}