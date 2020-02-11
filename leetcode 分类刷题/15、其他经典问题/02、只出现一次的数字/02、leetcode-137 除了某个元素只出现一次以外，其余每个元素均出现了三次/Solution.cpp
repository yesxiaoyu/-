// Author : lihongyu
// Time   : 2019-12-16

#include<bits/stdc++.h>
using namespace std;

// leetcode-137 只出现一次的数字：除了某个元素只出现一次以外，其余每个元素均出现了三次
// 思路：数字电路设计的思路，与136题类似，
// 在136题中我们使用异或运算使得相同的两个数运算的结果为0，
// 在本题中，我们需要思考的问题是，我们是否能够定义一种运算（代替异或），使得三个数运算的结果为 0
// 时间复杂度: O(n)
// 空间复杂度: O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for (auto x : nums) {
            b = (b ^ x) & ~a;
            a = (a ^ x) & ~b;
        }
        return b;
    }
};

class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (int i = 0; i < 32; i++) {
            int mask = 1 << i;
            int cnt = 0;
            for (int num : nums) {
                if ((num & mask) != 0) {
                    cnt++;
                }
            }
            if (cnt % 3 != 0) {
                ret |= mask;
            }
        }
        return ret;
    }
};

class Solution3 {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0, three;
        for (int num : nums) {
            // two的相应的位等于1，表示该位出现2次
            two |= (one & num);
            // one的相应的位等于1，表示该位出现1次
            one ^= num;
            // three的相应的位等于1，表示该位出现3次
            three = (one & two);
            // 如果相应的位出现3次，则该位重置为0
            two &= ~three;
            one &= ~three;
        }
        return one;
    }
};

// TODO：电路题，没理解，参见《剑指offer》思路

int main(){
    vector<int> arr = {0, 1, 0, 1, 0, 1, 99};
    cout<<Solution3().singleNumber(arr)<<endl;
    return 0;
}