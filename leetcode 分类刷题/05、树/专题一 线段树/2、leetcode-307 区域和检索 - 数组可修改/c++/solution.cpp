// Author : lihongyu
// Time   : 2019-12-16

#include<bits/stdc++.h>
using namespace std;

// leetcode-307 区域和检索 - 数组可变
// 思路：使用数组的效率高于线段树
// 时间复杂度: O(n)
// 空间复杂度: O(1)

class NumArray {
public:
    NumArray(vector<int>& nums) {
        res = nums;
    }

    void update(int i, int val) {
        res[i] = val;
    }

    int sumRange(int i, int j) {
        int total = 0;
        for(int k = i;k <= j;k++) {
            total += res[k];
        }
        return total;
    }
private:
    vector<int> res;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

// TODO：

int main(){
    vector<int> arr = {1, 3, 5};
    NumArray* na = new NumArray(arr);
    cout<<na->sumRange(0, 2)<<endl;
    na->update(1, 2);
    cout<<na->sumRange(0, 2)<<endl;
    return 0;
}