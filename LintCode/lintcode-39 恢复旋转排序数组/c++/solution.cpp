// Author : lihongyu
// Time   : 2019-12-17

#include<bits/stdc++.h>
using namespace std;

// lintCode-39 恢复旋转排序数组
// 思路：直接原地排序
// 时间复杂度: O(nlogn)
// 空间复杂度: O(1)

class Solution {
public:
    /**
     * @param nums: An integer array
     * @return: nothing
     */
    void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
        sort(nums.begin(), nums.end());
    }
};

// 思路：首先找到最小的数字，因为是顺序排序只不过旋转了，所以只用判断后一个是不是比前一个小就行了。找到了以后从前往后循环，直到那个最小的数字之前。
// 每一次循环都把第一位的数字插到最后一位，然后删除第一位数字。
// 时间复杂度: O(n)
// 空间复杂度: O(1)

class Solution2 {
public:
    /*
     * @param nums: An integer array
     * @return: nothing
     */
    void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
        if(nums.empty()) return;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] > nums[i+1]){        //找到起始数字
                for(int j = 0; j <= i; j++){
                    nums.push_back(nums[0]);
                    nums.erase(nums.begin());
                }
                break;
            }
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
    vector<int> arr = {4, 5, 1, 2, 3};
    Solution2().recoverRotatedSortedArray(arr);
    printVector(arr);
    return 0;
}