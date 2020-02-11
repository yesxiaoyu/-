// Author : lihongyu
// Time   : 2019-12-16

#include<bits/stdc++.h>
using namespace std;

// leetcode-136 只出现一次的数字：除了某个元素只出现一次以外，其余每个元素均出现两次
// 思路1：暴力，两层循环，外循环遍历，内循环找
// 思路2：排序
// 思路3：利用集合set，根据2*（a+b+c） - (a+a+b+b+c) = c求解
// 思路4：异或原理
// 时间复杂度: O(n)
// 空间复杂度: O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    }
};

class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        return accumulate(begin(nums), end(nums), 0, bit_xor<int>());
    }
};

class Solution3 {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int num : nums)
            res ^= num;
        return res;
    }
};

// TODO：

int main(){
    vector<int> arr = {4, 1, 2, 1, 2};
    cout<<Solution3().singleNumber(arr)<<endl;
    return 0;
}