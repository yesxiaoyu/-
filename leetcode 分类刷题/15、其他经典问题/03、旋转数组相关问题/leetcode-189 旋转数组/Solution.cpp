// Author : lihongyu
// Time   : 2019-12-17

#include<bits/stdc++.h>
using namespace std;

//参考：https://leetcode-cn.com/problems/rotate-array/solution/xuan-zhuan-shu-zu-by-leetcode/

// leetcode-189 旋转数组
// 思路：两次循环，每次挪一位，TLE
// 时间复杂度: O(n^2)
// 空间复杂度: O(1)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int tmp;
        for (int i = 0; i < k; i++) {
            tmp = nums[nums.size() - 1];
            for (int & num : nums) {
                swap(tmp, num);
            }
        }
    }
};

// 思路：用一个额外的数组来将每个元素放到正确的位置上，
// 也就是原本数组里下标为 i 的我们把它放到 (i+k)%数组长度的位置。
// 然后把新的数组拷贝到原数组中。
// 时间复杂度: O(n)
// 空间复杂度: O(n)

class Solution2 {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> tmp = vector<int>(nums.size());
        for (int i = 0; i < nums.size(); ++i)
            tmp[(i+k) % nums.size()] = nums[i];
        for (int i = 0; i < tmp.size(); ++i)
            nums[i] = tmp[i];
    }
};

// 思路：环状替换
// 时间复杂度: O(n)
// 空间复杂度: O(1)

class Solution3 {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        int count = 0;
        for (int start = 0; count < n; start++) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % n;
                swap(prev, nums[next]);
                current = next;
                count++;
            } while (start != current);
        }
    }
};

// 思路：使用反转。当我们旋转数组 k 次， k\%nk%n 个尾部元素会被移动到头部，剩下的元素会被向后移动。
// 在这个方法中，我们首先将所有元素反转。
// 然后反转前 k 个元素，再反转后面 n-kn−k 个元素，就能得到想要的结果。
// 时间复杂度: O(n)
// 空间复杂度: O(1)

class Solution4 {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }

private:
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
};

void printVector(vector<int> &arr){

    for (int i : arr) {
        cout<<i<<" ";
    }
    cout<<endl;
}

// TODO：

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    Solution4().rotate(arr, k);
    printVector(arr);
    return 0;
}